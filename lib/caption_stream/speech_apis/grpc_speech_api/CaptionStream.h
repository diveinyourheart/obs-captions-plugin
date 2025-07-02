#ifndef CPPTESTING_CAPTIONSTREAM_H
#define CPPTESTING_CAPTIONSTREAM_H

#include <functional>
#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <chrono>
#include <mutex>
#include "cameron314/blockingconcurrentqueue.h"

#include "ThreadsaferCallback.h"
#include "CaptionResult.h"

typedef unsigned int uint;
using namespace std;

typedef std::function<void(const CaptionResult &caption_result)> caption_text_callback;

struct CaptionStreamSettings {
    uint connect_timeout_ms;
    uint send_timeout_ms;
    uint recv_timeout_ms;

    uint max_queue_depth;
    uint download_thread_start_delay_ms;

    string language;
    int profanity_filter;
    string api_key;

    CaptionStreamSettings(
            uint connect_timeout_ms,
            uint send_timeout_ms,
            uint recv_timeout_ms,

            uint max_queue_depth,
            uint download_thread_start_delay_ms,
            const string &language,
            int profanity_filter,
            const string &api_key
    ) :
            connect_timeout_ms(connect_timeout_ms),
            send_timeout_ms(send_timeout_ms),
            recv_timeout_ms(recv_timeout_ms),

            max_queue_depth(max_queue_depth),
            download_thread_start_delay_ms(download_thread_start_delay_ms),
            language(language),
            profanity_filter(profanity_filter),
            api_key(api_key) {}

    bool operator==(const CaptionStreamSettings &rhs) const {
        return connect_timeout_ms == rhs.connect_timeout_ms &&
               send_timeout_ms == rhs.send_timeout_ms &&
               recv_timeout_ms == rhs.recv_timeout_ms &&
               max_queue_depth == rhs.max_queue_depth &&
               download_thread_start_delay_ms == rhs.download_thread_start_delay_ms &&
               language == rhs.language &&
               profanity_filter == rhs.profanity_filter &&
               api_key == rhs.api_key;
    }

    bool operator!=(const CaptionStreamSettings &rhs) const {
        return !(rhs == *this);
    }

//    CaptionStreamSettings() {};


    void print(const char *line_prefix = "") {
        printf("%sCaptionStreamSettings\n", line_prefix);
        printf("%s  connect_timeout_ms: %d\n", line_prefix, connect_timeout_ms);
        printf("%s  send_timeout_ms: %d\n", line_prefix, send_timeout_ms);
        printf("%s  recv_timeout_ms: %d\n", line_prefix, recv_timeout_ms);

        printf("%s  max_queue_depth: %d\n", line_prefix, max_queue_depth);
        printf("%s  download_thread_start_delay_ms: %d\n", line_prefix, download_thread_start_delay_ms);

//        printf("%s-----------\n", line_prefix);
    }
};


class CaptionStream : public std::enable_shared_from_this<CaptionStream>{
    string session_pair;
    moodycamel::BlockingConcurrentQueue<string *> audio_queue;
	std::atomic<bool> started = atomic<bool>(false);
	std::atomic<bool> stopped = atomic<bool>(false);


public:
    const CaptionStreamSettings settings;
    ThreadsaferCallback<caption_text_callback> on_caption_cb_handle;

    CaptionStream(
            const CaptionStreamSettings settings
    );

    bool start(std::shared_ptr<CaptionStream> self);

    void stop();

    bool is_stopped();

    bool queue_audio_data(const char *data, const uint data_size);

    string *dequeue_audio_data(const std::int64_t timeout_us);

    ~CaptionStream();
};

#endif //CPPTESTING_CAPTIONSTREAM_H
