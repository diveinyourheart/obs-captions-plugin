#include <obs.hpp>
#include <obs.h>
#include <obs-module.h>
#include <obs-frontend-api.h>
#include <obs-properties.h>

#include "SourceCaptioner.h"

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <media-io/audio-resampler.h>
#include <fstream>
#include <thread>


OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("my-plugin","en-US")

void finished_loading_event();

void stream_started_event();

void stream_stopped_event();

void recording_started_event();

void recording_stopped_event();

void virtualcam_started_event();

void virtualcam_stopped_event();

void obs_frontent_exiting();

void obs_frontent_scene_collection_changed();

static void obs_event(enum obs_frontend_event event, void*) {
	if (event == OBS_FRONTEND_EVENT_FINISHED_LOADING) {
		finished_loading_event()
	}
	else if (event == OBS_FRONTEND_EVENT_STREAMING_STARTED) {
		stream_started_event()
	}
	else if (event == OBS_FRONTEND_EVENT_STREAMING_STOPPED) {
		stream_stopped_event()
	}
	else if (event == OBS_FRONTEND_EVENT_RECORDING_STARTED) {
		recording_started_event()
	}
	else if (event == OBS_FRONTEND_EVENT_RECORDING_STOPPED) {
		recording_started_event()
	}
	else if (event == OBS_FRONTEND_EVENT_VIRTUALCAM_STARTED) {
		virtualcam_started_event();
	}
	else if (event == OBS_FRONTEND_EVENT_VIRTUALCAM_STOPPED) {
		virtualcam_stopped_event();
	}
	else if (event == OBS_FRONTEND_EVENT_EXIT) {
		obs_frontent_exiting();
	}
	else if (event == OBS_FRONTEND_EVENT_SCENE_COLLECTION_CHANGED) {
		obs_frontent_scene_collection_changed();
	}
	else if (event == OBS_FRONTEND_EVENT_STUDIO_MODE_ENABLED) {
		printf("studio mode!!!!!!!!!!!!!!!!!!!!\n");
	}
}

bool obs_module_load(void) {}
