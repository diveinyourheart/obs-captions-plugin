#include <utility>

#include "SourceAudioCaptureSession.h"
#include "log.c"

static void audio_captured(void *param, obs_source_t *source, const struct audio_data *audio, bool muted) {
    auto session = reinterpret_cast<SourceAudioCaptureSession*>(param);
    if (session)
        session->audio_capture_cb(source, audio, muted);
}

static void status_changed_fwder(void *param, calldata_t *calldata) {
    auto session = reinterpret_cast<SourceAudioCaptureSession*>(param);
    if (session)
        session->status_changed_check();
}

SourceAudioCaptureSession::SourceAudioCaptureSession(
        obs_source_t *audio_source,
        obs_source_t *muting_source,
        audio_chunk_data_cb audio_data_cb,
        audio_capture_status_change_cb status_change_cb,
        resample_info resample_to,
        source_capture_config muted_handling,
        bool send_startup_change_signal,
        int id
        ):
audio_source(audio_source),
muting_source(muting_source),
on_caption_cb_handle(audio_data_cb),
on_status_cb_handle(status_change_cb),
muted_handling(muted_handling),
use_muting_cb_signal(true),
bytes_per_channel(get_audio_bytes_per_channel(resample_to.format)),
resampler(nullptr),
id(id)
{
    debug_log("SourceAudioCaptureSession()");

    const struct audio_output_info *obs_audio = audio_output_get_info(obs_get_audio());
    if (!obs_audio)
        throw std::string("Failed to get OBS audio info");
    if (!audio_source)
        throw std::string("No audio capture source");
    if (!bytes_per_channel)
        throw std::string("Failed to get frame bytes size pre channel");
    if (obs_audio->samples_per_sec != resample_to.samples_per_sec
        || obs_audio->format != resample_to.format
        || obs_audio->speakers != resample_to.speakers) {
        resample_info src = {
            .samples_per_sec = obs_audio->samples_per_sec,
            .format = obs_audio->format,
            .speakers = obs_audio->speakers,
        };
        info_log("creating new resampler (%d, %d, %d) -> (%d, %d, %d)",
                 src.samples_per_sec, src.format, src.speakers,
                 resample_to.samples_per_sec, resample_to.format, resample_to.speakers);
        resampler = audio_resampler_create(&resample_to, &src);
        if (!resampler)
            throw std::string("Failed to create audio resampler");
    }

    const char *name = obs_source_get_name(audio_source);
    info_log("source %s active: %d", name, obs_source_active(audio_source));
    if (muting_source) {
        use_muting_cb_signal = false;
        const char *muting_name = obs_source_get_name(muting_source);
        info_log("using separarte muting source %s active: %d", muting_name, obs_source_active(muting_source));
    }else {
        muting_source = audio_source;
        info_log("using direct source %s active: %d", name, obs_source_active(audio_source));
    }

    if (!muting_source)
        throw std::string("No muting source is active");

    signal_handler_connect(obs_source_get_signal_handler(muting_source),"enable",status_changed_fwder,this);

    signal_handler_connect(obs_source_get_signal_handler(muting_source),"mute",status_changed_fwder,this);

    signal_handler_connect(obs_source_get_signal_handler(muting_source),"hide",status_changed_fwder,this);
    signal_handler_connect(obs_source_get_signal_handler(muting_source),"show",status_changed_fwder,this);

    signal_handler_connect(obs_source_get_signal_handler(muting_source),"activate",status_changed_fwder,this);
    signal_handler_connect(obs_source_get_signal_handler(muting_source),"deactivate",status_changed_fwder,this);

    obs_source_add_audio_capture_callback(audio_source, audio_captured, this);
    capture_status = check_source_status();
    if (send_startup_change_signal)
        status_changed_check(true);
}

void SourceAudioCaptureSession::status_changed_check(bool always_signal) {
    audio_source_capture_status new_status = check_source_status();
    if (!always_signal && new_status == capture_status) {
        return;
    }
    debug_log("SourceAudioCaptureSession %d status changed %s %d", id, obs_source_get_name(muting_source), new_status);
    capture_status = new_status;
    {
        std::lock_guard<std::recursive_mutex> lock(on_status_cb_handle.mutex);
        if (on_status_cb_handle.callback_fn)
            on_status_cb_handle.callback_fn(id, capture_status);
    }
}

audio_source_capture_status SourceAudioCaptureSession::check_source_status() {
    const bool is_muted = obs_source_muted(muting_source);
    const bool is_active = obs_source_active(muting_source);
    const bool is_showing = obs_source_showing(muting_source);
    const bool is_enabled = obs_source_enabled(muting_source);
    if (!is_active || !is_showing || !is_enabled)
        return AUDIO_SOURCE_NOT_STREAMED;
    if (is_muted)
        return AUDIO_SOURCE_MUTED;
    return AUDIO_SOURCE_CAPTURING;
}

void SourceAudioCaptureSession::audio_capture_cb(obs_source_t *source, const struct audio_data *audio, bool muted) {
    if (!on_caption_cb_handle.callback_fn)
        return;
    if (!audio || !audio->frames)
        return;
    if (muted && !use_muting_cb_signal) {
        muted = false;
        info_log("ignoring muted signal because other caption base");
    }
    if (muted || capture_status != AUDIO_SOURCE_CAPTURING) {
        if (muted_handling == MUTED_SOURCE_DISCARD_WHEN_MUTED)
            return;
        if (muted_handling == MUTED_SOURCE_REPLACE_WITH_ZERO) {
            const unsigned int size = audio->frames *bytes_per_channel;
            uint8_t *buffer = new uint8_t[size];
            memset(buffer, 0, size);
            {
                std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
                if (on_caption_cb_handle.callback_fn)
                    on_caption_cb_handle.callback_fn(id, buffer, size);
            }
            delete[] buffer;
            return;
        }
        if (muted_handling != MUTED_SOURCE_STILL_CAPTURE)
            return;
    }

    if (!resampler) {
        unsigned int size = audio->frames * bytes_per_channel;
        {
            std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
            if (on_caption_cb_handle.callback_fn)
                on_caption_cb_handle.callback_fn(id,audio->data[0], size);
        }
    }else {
        uint8_t *out[MAX_AV_PLANES];
        memset(out, 0, sizeof(out));

        uint32_t out_frames;
        uint64_t ts_offset;
        bool success = audio_resampler_resample(resampler,out,&out_frames,&ts_offset,
            (const uint8_t *const*)audio->data,audio->frames);
        if (!success || !out[0]) {
            warn_log("failed to resample audio");
            return;
        }

        unsigned int size = out_frames * bytes_per_channel;
        {
            std::lock_guard<std::recursive_mutex> lock(on_caption_cb_handle.mutex);
            if (on_caption_cb_handle.callback_fn)
                on_caption_cb_handle.callback_fn(id, out[0], size);
        }
    }
}

SourceAudioCaptureSession::~SourceAudioCaptureSession() {
    on_caption_cb_handle.clear();
    on_status_cb_handle.clear();

    obs_source_remove_audio_capture_callback(audio_source, audio_captured, this);

    signal_handler_disconnect(obs_source_get_signal_handler(muting_source), "enable", status_changed_fwder, this);

    signal_handler_disconnect(obs_source_get_signal_handler(muting_source), "mute", status_changed_fwder, this);

    signal_handler_disconnect(obs_source_get_signal_handler(muting_source), "hide", status_changed_fwder, this);
    signal_handler_disconnect(obs_source_get_signal_handler(muting_source), "show", status_changed_fwder, this);

    signal_handler_disconnect(obs_source_get_signal_handler(muting_source), "activate", status_changed_fwder, this);
    signal_handler_disconnect(obs_source_get_signal_handler(muting_source), "deactivate", status_changed_fwder, this);

    audio_resampler_destroy(resampler);

    debug_log("SourceAudioCaptureSession deconstructor");
}

audio_source_capture_status SourceAudioCaptureSession::get_current_capture_status() const {
    return capture_status;
}
