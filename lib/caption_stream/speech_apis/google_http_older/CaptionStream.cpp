#include <utility>

#include <string>
#include <sstream>
#include "CaptionStream.h"
#include "utils.h"

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

	if (self.get() != this)
		return false;

	if (started)
		return false;

	started = true;
	auto self = shared_from_this();
	upstream_thread = std::make_unique<std::thread>([this, self] {
		this->upstream_run(self);
		})
	return true;
}
