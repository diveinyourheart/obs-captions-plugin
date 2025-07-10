#ifndef OBS_GOOGLE_CAPTION_PLUGIN_DATA_H
#define OBS_GOOGLE_CAPTION_PLUGIN_DATA_H

#define AUDIO_OUTPUT_CAPTURE_ALL_AUDIO_SOURCE_NAME  \
    "______________________________________audio_output_capture___all_audio_source_lets_hope_no_one_ever_names_a_obs_source_list_this_"

#include <string>
#include <functional>

static bool is_all_audio_output_capture_source_data(const std::string &data) {
    return data.find(AUDIO_OUTPUT_CAPTURE_ALL_AUDIO_SOURCE_NAME) == 0;
}

static int all_audio_output_capture_source_track_index(const std::string &Data) {
    if (!is_all_audio_output_capture_source_data(Data)) {
        return -1;
    }
    const std::string rest = Data.substr(strlen(AUDIO_OUTPUT_CAPTURE_ALL_AUDIO_SOURCE_NAME));
    try {
        return std::stoi(rest);
    }catch (...) {
        return -1;
    }
}

static std::string all_audio_output_capture_source_name(const int track_index) {
    return "Stream Audio (Track " + std::to_string(track_index + 1) + ")";
}

static std::string all_audio_output_capture_source_data(const int track_index) {
    return AUDIO_OUTPUT_CAPTURE_ALL_AUDIO_SOURCE_NAME + std::to_string(track_index);
}

static std::string corrected_streaming_audio_output_capture_source_name(const std::string &data) {
    const int track_index = all_audio_output_capture_source_track_index(data);
    if (track_index > 0) {
        return all_audio_output_capture_source_name(track_index);
    }
    return data;
}

enum audio_source_capture_status {
    AUDIO_SOURCE_CAPTURING = 1,
    AUDIO_SOURCE_MUTED = 2,
    AUDIO_SOURCE_NOT_STREAMED = 3,
};

enum source_capture_config {
    MUTED_SOURCE_DISCARD_WHEN_MUTED,
    MUTED_SOURCE_REPLACE_WITH_ZERO,
    MUTED_SOURCE_STILL_CAPTURE,
};

using audio_chunk_data_cb = std::function<void(const int, const uint8_t*, const size_t)>;
using audio_capture_status_change_cb = std::function<void(const int, const audio_source_capture_status)>;

#endif //OBS_GOOGLE_CAPTION_PLUGIN_DATA_H
