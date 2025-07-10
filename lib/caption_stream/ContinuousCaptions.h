#ifndef CPPTESTING_CONTINUOUSCAPTIONS_H
#define CPPTESTING_CONTINUOUSCAPTIONS_H

#include <functional>
#include "CaptionStream.h"

struct ContinuousCaptionStreamSettings {
    uint connect_second_after_secs;
    uint switchover_second_after_secs;

    uint minimum_reconnect_interval_secs;

    CaptionStreamSettings stream_settings;

    ContinuousCaptionStreamSettings(
        uint connectSecondAfterSecs,
        uint switchoverSecondAfterSecs,
        uint minimumReconnectIntervalSecs,
        CaptionStreamSettings streamSettings
        ):
        connect_second_after_secs(connectSecondAfterSecs),
        switchover_second_after_secs(switchoverSecondAfterSecs),
        minimum_reconnect_interval_secs(minimumReconnectIntervalSecs),
        stream_settings(streamSettings)
    {}

    bool operator==(const ContinuousCaptionStreamSettings &other) const {
        return connect_second_after_secs == other.connect_second_after_secs &&
                switchover_second_after_secs == other.switchover_second_after_secs &&
                minimum_reconnect_interval_secs == other.minimum_reconnect_interval_secs &&
                stream_settings == other.stream_settings;
    }

    bool operator!=(const ContinuousCaptionStreamSettings &other) const {
        return !(*this == other);
    }

    void print(const char *line_prefix = "") {
        printf("%sContinuousCaptionStreamSettings\n", line_prefix);
        printf("%s  connect_second_after_secs: %d\n", line_prefix, connect_second_after_secs);
        printf("%s  switchover_second_after_secs: %d\n", line_prefix,switchover_second_after_secs);
        printf("%s  minimum_reconnect_interval_secs: %d\n", line_prefix, minimum_reconnect_interval_secs);
        stream_settings.print((string(line_prefix) + "  ").c_str());
    }
};

using continuous_caption_text_callback = std::function<void(const CaptionResult &caption_result, bool interrupted)>;

class ContinuousCaptions {
    std::shared_ptr<CaptionStream> current_stream;
    std::shared_ptr<CaptionStream> prepared_stream;

    using time_point = std::chrono::steady_clock::time_point;

    time_point current_started_at;
    time_point prepared_started_at;

    ContinuousCaptionStreamSettings settings;
    std::unique_ptr<CaptionResult> last_caption_result;

    void on_caption_text_cb(const CaptionResult &caption_result);

    void start_prepared();

    void clear_prepared();

    void cycle_stream();

    public:
    ThreadsaferCallback<continuous_caption_text_callback> on_caption_cb_handle;

    explicit ContinuousCaptions(ContinuousCaptionStreamSettings &settings);

    bool queue_audio_data(const char* data, uint data_size);

    ~ContinuousCaptions();
};

#endif