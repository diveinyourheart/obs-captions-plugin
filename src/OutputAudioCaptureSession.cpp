#include "OutputAudioCaptureSession.h"

#include <utility>
#include <util/platform.h>

#include "speech_apis/google_http_older/log.h"

static void audio_captured(void *param, size_t mix_idx, struct audio_data *audio) {
    auto session = reinterpret_cast<OutputAudioCaptureSession*>(param);
    if (session)
        session->audio_capture_cb(mix_idx, audio);
}

OutputAudioCaptureSession::OutputAudioCaptureSession(
        int track_index,
        audio_chunk_data_cb on_caption_cb_handle,
        audio_capture_status_change_cb on_status_cb_handle,
        resample_info resample_to,
        int id
        ):
on_caption_cb_handle(on_caption_cb_handle),
on_status_cb_handle(on_status_cb_handle),
bytes_per_channel(get_audio_bytes_per_channel(resample_to.format)),
track_index(track_index),
id(id) {
    debug_log("OutputAudioCaptureSession()");
    obs_audio_info backend_audio_settings;
    if (!obs_get_audio_info(&backend_audio_settings)) {
        throw std::string("failed to obtain backend audio settings");
    }

    debug_log("output audio_info track %d: %d, %d",
              track_index, backend_audio_settings.samples_per_sec, backend_audio_settings.speakers);

    if (!bytes_per_channel)
        throw std::string("failed to obtain frame bytes size per channel");

    converter.speakers = resample_to.speakers;
    converter.format = resample_to.format;
    converter.samples_per_sec = resample_to.samples_per_sec;

    audio_output = obs_get_audio();
    if (!audio_output) {
        throw std::string("failed to obtain audio output");
    }
    audio_output_connect(audio_output,track_index,&converter,audio_captured,this);
}

void OutputAudioCaptureSession::audio_capture_cb(size_t mix_idx,const struct audio_data *audio) {
    if (!on_caption_cb_handle.callback_fn)
        return;
    if (!audio||!audio->frames)
        return;
    unsigned int size = audio->frames * bytes_per_channel;
    {
        std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
        if (on_caption_cb_handle.callback_fn)
            on_caption_cb_handle.callback_fn(id,audio->data[0],size);
    }
}

OutputAudioCaptureSession::~OutputAudioCaptureSession() {
    on_caption_cb_handle.clear();
    on_status_cb_handle.clear();

    audio_output_disconnect(audio_output,track_index,audio_captured,this);
    debug_log("OutputAudioCaptureSession::~OutputAudioCaptureSession()");
}
