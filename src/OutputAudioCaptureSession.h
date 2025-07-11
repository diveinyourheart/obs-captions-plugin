#pragma once

#include <obs.h>
#include <obs-module.h>
#include <obs-frontend-api.h>
#include <media-io/audio-resampler.h>
#include <obs.hpp>
#include <functional>
#include <mutex>
#include <lib/caption_stream/ThreadsaferCallback.h>
#include "data.h"

class OutputAudioCaptureSession {
    const int id;
    struct audio_convert_info converter;
    audio_t *audio_output =nullptr;
    const int bytes_per_channel;
    const int track_index;
public:
    ThreadsaferCallback<audio_chunk_data_cb> on_caption_cb_handle;
    ThreadsaferCallback<audio_capture_status_change_cb> on_status_cb_handle;

    OutputAudioCaptureSession(
        int track_index,
        audio_chunk_data_cb on_caption_cb_handle,
        audio_capture_status_change_cb on_status_cb_handle,
        resample_info resample_to,
        int id
        );

    void audio_capture_cb(size_t mix_idx, const struct audio_data *audio);

    ~OutputAudioCaptureSession();
};
