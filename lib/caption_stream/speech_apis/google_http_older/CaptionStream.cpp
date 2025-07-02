#include <utility>

#include <string>
#include <sstream>
#include "CaptionStream.h"
#include "utils.h"
#include "log.h"

#define BUFFER_SIZE 4096

#include "json11.cpp"

using namespace json11;

/*
{
  "result": [
    {
      "alternative": [
	{
	  "transcript": "Hello world",
	  "confidence": 0.9
	}
      ],
      "final": true,
      "stability": 0.8
    }
  ],
  "result_index": 0
}
*/

static CaptionResult* parse_caption_obj(const string& msg_obj,
	const std::chrono::steady_clock::time_point& first_received_at,
	const std::chrono::steady_clock::time_point& received_at
) {
	bool is_final = false;
	double highest_stability = 0.0;
	string caption_text;
	int result_index;

	string err;
	Json json = Json::parse(msg_obj, err);
	if (!err.empty()) {
		throw err;
	}
	Json result_val = json["result"];
	if (!result_val.is_array())
		throw string("no result");

	if (!result_val.array_items().size())
		throw string("empty");

	Json result_index_val = json["result_index"];
	if (!result_index_val.is_number())
		throw string("no result index");

	result_index = result_index_val.int_value();

	for (auto& result_obj : result_val.array_items()) {
		string text = result_obj["alternative"][0]["transcript"].string_value();
		if (text.empty())
			continue;

		if (result_obj["final"].bool_value()) {
			is_final = true;
			caption_text = text;
			break;
		}

		Json stability_val = result_obj["stability"];
		if (!stability_val.is_number())
			continue;

		if (stability_val.number_value() >= highest_stability) {
			caption_text = text;
			highest_stability = stability_val.number_value();
		}
		//        info_log("val %s", text_val.dump().c_str());

		//        printf("Result: %s\n", json.dump().c_str());
		//        cout<< a.dump() << endl;
		//        printf("Result: %s\n", json.dump().c_str());
	}

	if (caption_text.empty())
		throw string("no caption text");

	//    debug_log("stab: %f, final: %d, index: %d, text: '%s'", highest_stability, is_final, result_index, caption_text.c_str());
	return new CaptionResult(result_index, is_final, highest_stability, caption_text, msg_obj, first_received_at, received_at);
}

int read_until_contains(TcpConnection* connection, string& buffer, const char* required_contents) {
	int newline_pos = buffer.find(required_contents);
	if (newline_pos != string::npos)
		return newline_pos;
	char chunk[BUFFER_SIZE];
	do {
		int read_cnt = connection->receive_at_most(chunk, BUFFER_SIZE);
		if (read_cnt <= 0)
			return -1;
		buffer.append(chunk, read_cnt);
	} while ((newline_pos = buffer.find(required_contents)) == string::npos);
	return newline_pos;
}

CaptionStream::CaptionStream(
	CaptionStreamSettings settings
) : upstream(TcpConnection(GOOGLE, PORTUP)),
downstream(TcpConnection(GOOGLE, PORTDOWN)),

settings(settings),

session_pair(random_string(15)),
upstream_thread(nullptr),
downstream_thread(nullptr) {

	debug_log("CaptionStream Google HTTP, created session pair: %s", session_pair.c_str());
}

bool CaptionStream::start() {

	auto self = shared_from_this();
	if (self.get() != this)
		return false;

	if (started)
		return false;

	started.store(true);
	upstream_thread = std::make_unique<std::thread>([this, self] {
		this->upstream_run(self);
		});
	return true;
}

void CaptionStream::upstream_run(const std::shared_ptr<CaptionStream> &self)
{
	debug_log("starting upstream_run() %s",session_pair.c_str());
	_upstream_run(self);
	stop();
	debug_log("finished upstream_run() %s",session_pair.c_str());
}

void CaptionStream::downstream_run(const std::shared_ptr<CaptionStream> &self)
{
	debug_log("starting downstream_run() %s",session_pair.c_str());
	_downstream_run();
	stop();
	debug_log("finished downstream_run() %s",session_pair.c_str());
}

void CaptionStream::_upstream_run(const std::shared_ptr<CaptionStream> &self)
{
	try {
		upstream.connect(settings.connect_timeout_ms);
	}catch(ConnectionError& e) {
		debug_log("upstream connect error, %s",e.what());
		return;
	}
	debug_log("upstream connected!");
	upstream.set_timeout(settings.send_timeout_ms);
	string post_req("POST /speech-api/full-duplex/v1/up?key=");
	post_req.append(settings.api_key);
	post_req.append("&pair=");
	post_req.append(session_pair);
	post_req.append("&lang=");
	post_req.append(settings.language);
	if (settings.profanity_filter)
		post_req.append("&pFilter=1");
	else
		post_req.append("&pFilter=0");
	post_req.append("&client=chromium&continuous&interim HTTP/1.1\r\n"
		    "Host: www.google.com\r\n"
		    "content-type: audio/l16; rate=16000\r\n"
		    "Accept: */\r\n"
		    "Accept-Encoding: gzip, deflat\r\n"
		    "User-Agent: TwitchStreamCaptioner ThanksGoogle\r\n"
		    "Transfer-Encoding: chunked\r\n"
		    "\r\n");
	info_log("GOOGLE_API_KEY_STR: '%s'", GOOGLE_API_KEY_STR);
	if (!upstream.send_all(post_req.c_str(), post_req.length())) {
		error_log("upstream send head error");
		return;
	}
	if (is_stopped()) {
		return;
	}
	debug_log("post: %s", post_req.c_str());
	debug_log("sent head bytes %lu, language: %s, profanity filter: %d",
		  post_req.size(), settings.language.c_str(), settings.profanity_filter);
	if (downstream_thread) {
		error_log("already has downstream thread");
		return;
	}
	downstream_thread = std::make_unique<std::thread>([this,self] {
		this->downstream_run(self);
	});
	const string crlf = "\r\n";
	uint chunk_count = 0;
	while (true) {
		if (is_stopped())
			return;
		string* audio_chunk = dequeue_audio_data(settings.send_timeout_ms * 1000);
		if (audio_chunk == nullptr) {
			error_log("couldn't deque audio chunk in time");
			return;
		}
		if (!audio_chunk->empty()) {
			std::stringstream stream;
			stream<<std::hex<<audio_chunk->length()<<crlf<<*audio_chunk<<crlf;
			std::string request = stream.str();
			if (!upstream.send_all(request.c_str(), request.length())) {
				error_log("couldn't send audio chunk");
				delete audio_chunk;
				return;
			}

			if (chunk_count %1000 == 0) {
				debug_log("sent audio chunk %d, %lu bytes", chunk_count, audio_chunk->length());
			}
		}else {
			error_log("got 0 size audio chunk. ignoring");
		}
		delete audio_chunk;
		chunk_count++;
	}
}

void CaptionStream::_downstream_run()
{
	const uint crlf_len = 2;
	if (settings.download_thread_start_delay_ms) {
		debug_log("waiting %d ms to start download connection", settings.download_thread_start_delay_ms);
		std::this_thread::sleep_for(std::chrono::milliseconds(settings.download_thread_start_delay_ms));
	}
	try {
		downstream.connect(settings.connect_timeout_ms);
	} catch (ConnectError& e) {
		error_log("downstream connect() error, %s", ex.what());
		return;
	}
	if (is_stopped())
		return;
	debug_log("downstream connected!");
	downstream.set_timeout(settings.send_timeout_ms);

	string get_req("GET /speech-api/full-duplex/v1/down?pair=");
	get_req.append(session_pair);
	get_req.append(" HTTP/1.1\r\n"
		   "Host: www.google.com\r\n"
		   "Accept: */*\r\n"
		   //                   "Accept-Encoding: gzip, deflate\r\n"
		   "User-Agent: TwitchStreamCaptioner ThanksGoogle\r\n"
		   "\r\n");

	if (!downstream.send_all(get_req.c_str(), get_req.length())) {
		error_log("downstream send head error");
		return;
	}
	if (is_stopped())
		return;
	debug_log("downstream header sent, %lu bytes!", get_req.size());
	downstream.set_timeout(settings.recv_timeout_ms);
	string head;
	const int newline_pos = read_until_contains(&downstream,head,"\r\n\r\n");
	if (newline_pos == -1) {
		error_log("downstream read head error");
		return;
	}

	if (head.find("HTTP/1.1 200 OK") != 0) {
		error_log("downstream invalid response %s", head.c_str());
		return;
	}

	if (is_stopped())
		return;
	string rest = head.substr(newline_pos + crlf_len + crlf_len,std::string::npos);
	unsigned long chunk_length = 0;
	int crlf_pos;
	std::chrono::steady_clock::time_point first_received_at;
	bool update_first_received_at = true;
	while (true) {
		crlf_pos = read_until_contains(&downstream,rest,"\r\n");
		if (crlf_pos <= 0) {
			error_log("downstream read chunksize error, rest: %lu %s", rest.size(), rest.c_str());
			return;
		}
		if (is_stopped())
			return;
		try {
			chunk_length = std::stoul(rest.substr(0,crlf_pos),nullptr,16);
		}catch (...) {
			error_log("downstream parse chunksize error, %s", rest.c_str());
			return;
		}
		uint chunk_data_start = crlf_pos + crlf_len;
		uint existing_chunk_byte_cnt = rest.length() - chunk_data_start;
		int needed_bytes = ((int) chunk_length) - existing_chunk_byte_cnt + crlf_len;

		if (needed_bytes > 0) {
			debug_log("reading chunk, size: %lu, existing_chunk_byte_cnt: %d, needed %d",
				chunk_length, existing_chunk_byte_cnt, needed_bytes);
			int read = downstream.receive_at_least(rest,needed_bytes);
			if (read <= 0 || read < needed_bytes) {
				error_log("downstream read chunk data error, fun: downstream.receive_at_least");
				return;
			}
		}
		if (is_stopped())
			return;
		if (chunk_length) {
			string chunk_data = rest.substr(crlf_pos + crlf_len,chunk_length);
			if (chunk_data.size() != chunk_length) {
				error_log("downstream read chunk data error, too few bytes, wtf, %lu %lu", chunk_data.size(), chunk_length);
				return;
			}
			try {
				auto now = std::chrono::steady_clock::now();
				if (update_first_received_at)
					first_received_at = now;
				debug_log("Caption stream read: %d, %lu,  %s", chunk_data_start, chunk_length, chunk_data.c_str());
				CaptionResult *result = parse_caption_obj(chunk_data,first_received_at,now);
				debug_log("Caption stream raw_message: %s", result->raw_message.c_str());
				debug_log("Caption stream caption_text: %s", result->caption_text.c_str());
				update_first_received_at = result->final;
				{
					std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
					if (on_caption_cb_handle.callback_fn) {
						debug_log("calling caption cb");
						on_caption_cb_handle.callback_fn(*result);
					}
				}
				delete result;
			}catch (string &ex) {
				info_log("couldn't parse caption message. Error: '%s'. Messsage: '%s'", ex.c_str(), chunk_data.c_str());
			}catch (...) {
				info_log("couldn't parse caption message. Messsage: '%s'", chunk_data.c_str());
			}
			if (is_stopped())
				return;
			info_log("downstream chunk: %lu bytes, %s", chunk_data.size(), chunk_data.c_str());
		}else {
			info_log("ignoring zero data chunk");
		}
		rest.erase(0,chunk_data_start + chunk_length + crlf_len);
	}
}

bool CaptionStream::is_stopped() const
{
	return stopped.load();
}

bool CaptionStream::queue_audio_data(const char *data, const uint data_size)
{
	if (is_stopped())
		return false;
	string *str = new string(data, data_size);

	const int over_limit_cnt = audio_queue.size_approx() - settings.max_queue_depth;
	if (settings.max_queue_depth) {
		int cleared_cnt = 0;
		while (audio_queue.size_approx() > over_limit_cnt) {
			string *item;
			if (audio_queue.try_dequeue(item)) {
				delete item;
				cleared_cnt++;
			}
		}
		if (cleared_cnt) {
			debug_log("queue too big, dropped %d old items from queue %s", cleared_cnt, session_pair.c_str());
		}
	}
	audio_queue.enqueue(str);
	return true;
}

string *CaptionStream::dequeue_audio_data(const std::int64_t timeout_us)
{
	string *ret = nullptr;
	if (audio_queue.wait_dequeue_timed(ret,timeout_us))
		return ret;
	return nullptr;
}

void CaptionStream::stop()
{
	info_log("stop1! %s", this->session_pair.c_str());
	on_caption_cb_handle.clear();
	stopped.store(true);

	string *to_unblock_uploader = new string();
	audio_queue.enqueue(to_unblock_uploader);
	info_log("stop2! %s", this->session_pair.c_str());
}

CaptionStream::~CaptionStream()
{
	debug_log("~CaptionStream deconstructor %s", this->session_pair.c_str());
	if (!is_stopped())
		stop();
	int cleared = 0;
	{
		string *item;
		while (audio_queue.try_dequeue(item)) {
			delete item;
			cleared++;
		}
	}
	debug_log("~CaptionStream deleting %s", this->session_pair.c_str());
	if (upstream_thread)
		upstream_thread->detach();
	if (downstream_thread)
		downstream_thread->detach();
	debug_log("~CaptionStream deconstructor done %s, deleted left %d in queue", this->session_pair.c_str(), cleared);
}

bool CaptionStream::is_started() const
{
	return started.load();
}