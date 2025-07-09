#include <utility>

#include "ContinuousCaptions.h"
#include "log.h"

ContinuousCaptions::ContinuousCaptions(ContinuousCaptionStreamSettings &settings)
    :settings(settings),current_stream(nullptr),prepared_stream(nullptr){}

bool ContinuousCaptions::queue_audio_data(const char* data, const uint data_size) {
    if (!data_size) {
        return false;
    }
    if (!current_stream) {
        debug_log("first time, no current stream, cycling");
        cycle_stream();
    }
    if (!current_stream) {
        debug_log("still no current stream");
        return false;
    }

    double secs_since_start = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - current_started_at).count();

    if (current_stream->is_stopped()) {
        if (settings.minimum_reconnect_interval_secs && secs_since_start < settings.minimum_reconnect_interval_secs) {
            debug_log("current stream dead, not reconnecting yet, too soon, %f %u",
                      secs_since_start, settings.minimum_reconnect_interval_secs);
            return false;
        }
        debug_log("current stream dead,cycling, %f", secs_since_start);
        cycle_stream();
    }

    if (settings.switchover_second_after_secs && secs_since_start > settings.switchover_second_after_secs) {
        if (prepared_stream) {
            if (prepared_stream->is_stopped()) {
                debug_log("trying to switch to prepared stream but dead, recreating");
                clear_prepared();
                start_prepared();
            }else {
                debug_log("switching over to prepared stream, %f > %u", secs_since_start, settings.switchover_second_after_secs);
                cycle_stream();
            }
        }
    }else if (settings.connect_second_after_secs && secs_since_start > settings.connect_second_after_secs) {
        if (!prepared_stream || prepared_stream->is_stopped()) {
            debug_log("starting second stream %f", secs_since_start);
            start_prepared();
        }else {
            debug_log("double queue");
            prepared_stream->queue_audio_data(data, data_size);
        }
    }
    return current_stream->queue_audio_data(data, data_size);
}

void ContinuousCaptions::cycle_stream() {
    debug_log("cycle_stream");
    if (current_stream) {
        current_stream->stop();
        current_stream = nullptr;
    }
    if (prepared_stream && prepared_stream->is_stopped()) {
        prepared_stream->stop();
        prepared_stream = nullptr;
    }
    if (last_caption_result && !last_caption_result->final) {
        debug_log("stream interrupted, last result was not final, sending copy of last with fixed final=true");
        last_caption_result->final = true;
        {
            std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
            if (on_caption_cb_handle.callback_fn) {
                on_caption_cb_handle.callback_fn(*last_caption_result, true);
            }
        }
    }
    last_caption_result = nullptr;
    const caption_text_callback cb = [this](auto && PH1) { on_caption_text_cb(std::forward<decltype(PH1)>(PH1)); };
    if (prepared_stream) {
        debug_log("cycling stream, using prepared connection");
        current_stream = prepared_stream;
        current_started_at = prepared_started_at;
        current_stream->on_caption_cb_handle.set(cb);
    }else {
        debug_log("cycling streams, creating new connection");
        current_stream = std::make_shared<CaptionStream>(settings.stream_settings);
        current_stream->on_caption_cb_handle.set(cb);
        if (!current_stream->start()) {
            error_log("failed to start caption stream");
        }
        current_started_at = std::chrono::steady_clock::now();
    }
    prepared_stream = nullptr;
}

void ContinuousCaptions::start_prepared() {
    debug_log("starting second prepared connection");
    clear_prepared();
    prepared_stream = std::make_shared<CaptionStream>(settings.stream_settings);
    if (!prepared_stream->start()) {
        error_log("FAILED starting prepared connection");
    }
    prepared_started_at = std::chrono::steady_clock::now();
}

void ContinuousCaptions::clear_prepared() {
    if (!prepared_stream) {
        return;
    }
    debug_log("clearing prepared connection");
    prepared_stream->stop();
    prepared_stream = nullptr;
}

void ContinuousCaptions::on_caption_text_cb(const CaptionResult &caption_result) {
    {
        std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
        last_caption_result = std::make_unique<CaptionResult>();
        *last_caption_result = caption_result;
        if (on_caption_cb_handle.callback_fn) {
            on_caption_cb_handle.callback_fn(*last_caption_result, false);
        }

    }
}

ContinuousCaptions::~ContinuousCaptions() {
    debug_log("~ContinuousCaptions deconstructor");
    on_caption_cb_handle.clear();
    if (current_stream) {
        current_stream->stop();
    }
    if (prepared_stream) {
        prepared_stream->stop();
    }
}
