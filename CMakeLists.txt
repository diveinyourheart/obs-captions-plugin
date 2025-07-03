cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(VERSION_STRING "0.30")

add_subdirectory(lib/caption_stream)
add_library(obs_google_caption_plugin MODULE)
add_library(OBS::obs_google_caption_plugin ALIAS obs_google_caption_plugin)

set(ENABLE_CUSTOM_API_KEY OFF CACHE BOOL "set API key via settings UI field")
set(GOOGLE_API_KEY "" CACHE STRING "google api key with speech API enabled")

if (GOOGLE_API_KEY AND ENABLE_CUSTOM_API_KEY)
    message(FATAL_ERROR "both GOOGLE_API_KEY and ENABLE_CUSTOM_API_KEY set, not supported")
endif ()

if (ENABLE_CUSTOM_API_KEY)
    message("ENABLE_CUSTOM_API_KEY on, using UI api key")
    set(PLUGIN_COMPILE_DEFINITIONS ENABLE_CUSTOM_API_KEY=1)
elseif (GOOGLE_API_KEY)
    message("using fixed GOOGLE_API_KEY")
    set(PLUGIN_COMPILE_DEFINITIONS GOOGLE_API_KEY_STR="${GOOGLE_API_KEY}")
else ()
    message(FATAL_ERROR "no GOOGLE_API_KEY set and no ENABLE_CUSTOM_API_KEY=ON either")
endif ()

set(obs_google_caption_plugin_SOURCES
#        src/ui/MainCaptionWidget.cpp
#        src/ui/CaptionSettingsWidget.cpp
#
#        src/SourceAudioCaptureSession.cpp
#        src/OutputAudioCaptureSession.cpp
        src/SourceCaptioner.cpp
#        src/CaptionResultHandler.cpp
#
#        src/google_s2t_caption_plugin.cpp
#        src/CaptionPluginManager.cpp
#        src/ui/CaptionDock.cpp
#        src/ui/OpenCaptionSettingsWidget.cpp
)

set(obs_google_caption_plugin_HEADERS
#        src/SourceAudioCaptureSession.h
#        src/OutputAudioCaptureSession.h
        src/SourceCaptioner.h
        #        src/CaptionResultHandler.cpp
#
#        src/ui/MainCaptionWidget.h
#        src/ui/CaptionSettingsWidget.h
#        src/caption_output_writer.h
#        src/CaptionPluginManager.h
#        src/ui/CaptionDock.h
#        src/ui/OpenCaptionSettingsWidget.h
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

#set(obs_QRC src/resources/obs.qrc)

find_package(Qt6 COMPONENTS Widgets Core)
IF (Qt6_FOUND)
    message("using Qt6: ${Qt6_DIR}")
#    qt_add_resources(obs_QRC_SOURCES ${obs_QRC})
    set(_qt_widgets Qt6::Widgets)
else ()
    find_package(Qt5 REQUIRED COMPONENTS Widgets Core)
    message("using Qt5: ${Qt5_DIR}")
#    qt5_add_resources(obs_QRC_SOURCES ${obs_QRC})
    set(_qt_widgets Qt5::Widgets)
ENDIF ()

target_sources(obs_google_caption_plugin PRIVATE ${obs_google_caption_plugin_SOURCES} ${obs_google_caption_plugin_HEADERS})
target_include_directories(obs_google_caption_plugin PUBLIC ${OBS_SOURCE_DIR}/libobs ${OBS_SOURCE_DIR}/UI/obs-frontend-api)
target_link_libraries(obs_google_caption_plugin PRIVATE caption_stream ${_qt_widgets} OBS::libobs OBS::frontend-api)

set_target_properties_obs(obs_google_caption_plugin PROPERTIES FOLDER plugins PREFIX "")