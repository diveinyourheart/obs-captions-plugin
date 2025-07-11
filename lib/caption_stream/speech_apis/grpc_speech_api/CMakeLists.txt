cmake_minimum_required(VERSION 3.12)

add_library(speech_api_stream SHARED)
add_library(OBS::speech_api_stream ALIAS speech_api_stream)

set(USE_PKG_CONFIG_GRPC "" CACHE BOOL "Use pkgconfig to automatically find grpc and ")
set(GOOGLEAPIS_DIR "/Users/bytedance/develop/googleapis" CACHE STRING "Path containing grpc generated googleapis files")
set(USE_OS_CERTS "" CACHE STRING "let GRPC use the OS cert store")
#set(gRPC_DIR "/Users/bytedance/.local/lib/cmake/grpc")
#set(Protobuf_DIR "/Users/bytedance/.local/lib/cmake/protobuf")

if (USE_PKG_CONFIG_GRPC)
    message("using pkgconfig")
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(Protobuf REQUIRED protobuf)
    pkg_check_modules(GRPCPP REQUIRED grpc++)
    message("FOUND gRPC!")

    message("Protobuf_INCLUDE_DIRS ${Protobuf_INCLUDE_DIRS}")
    message("GRPCPP_INCLUDE_DIRS ${GRPCPP_INCLUDE_DIRS}")

    message("Protobuf_LIBRARY_DIRS ${Protobuf_LIBRARY_DIRS}")
    message("GRPCPP_LIBRARY_DIRS ${GRPCPP_LIBRARY_DIRS}")

    SET(GRPC_NAME grpc)
else ()
    message("using find_package")

    find_package(Protobuf CONFIG REQUIRED)
    find_package(gRPC CONFIG REQUIRED)
    message("FOUND gRPC!")

    message("gRPC_DIR ${gRPC_DIR}")
    message("Protobuf_DIR ${Protobuf_DIR}")

    SET(GRPC_NAME gRPC::grpc++)
endif ()

if (GOOGLEAPIS_DIR)
    # check if the main cloud speech file exists to check if the given dir is correct
    set(_SPEECH_FILE "google/cloud/speech/v1/cloud_speech.grpc.pb.h")
    if (EXISTS "${GOOGLEAPIS_DIR}/${_SPEECH_FILE}")
        SET(GOOGLEAPIS_PATH "${GOOGLEAPIS_DIR}")
    elseif (EXISTS "${GOOGLEAPIS_DIR}/gens/${_SPEECH_FILE}")
        SET(GOOGLEAPIS_PATH "${GOOGLEAPIS_DIR}/gens")
    else ()
        message(FATAL_ERROR "GOOGLEAPIS_PATH appears invalid, no ${_SPEECH_FILE} found: ${GOOGLEAPIS_DIR} ${CMAKE_CURRENT_SOURCE_DIR}")
    endif ()
else ()
    message(FATAL_ERROR "no GOOGLEAPIS_DIR")
endif ()

message("using GOOGLEAPIS_PATH: ${GOOGLEAPIS_PATH}")

file(GLOB_RECURSE GOOGLE_API
        ${GOOGLEAPIS_PATH}/google/api/http*.cc
        ${GOOGLEAPIS_PATH}/google/api/field_behavior*.cc
        ${GOOGLEAPIS_PATH}/google/api/client*.cc
        ${GOOGLEAPIS_PATH}/google/api/annotations*.cc
        ${GOOGLEAPIS_PATH}/google/api/resource*.cc
)
file(GLOB_RECURSE GOOGLE_RPC ${GOOGLEAPIS_PATH}/google/rpc/*.cc)
file(GLOB_RECURSE GOOGLE_LONGRUNNING ${GOOGLEAPIS_PATH}/google/longrunning/*.cc)
file(GLOB_RECURSE GOOGLE_SPEECH ${GOOGLEAPIS_PATH}/google/cloud/speech/v1/*.cc)

set(_GOOGLE_API_FILES_NAT
        ${GOOGLE_API}
        ${GOOGLE_RPC}
#        ${GOOGLE_TYPE}
#        ${GOOGLE_LOGGING}
        ${GOOGLE_LONGRUNNING}
        ${GOOGLE_SPEECH}
)

# fix all globbed Windows path backslashes '\' to '/' otherwise add_library() gives an error
set(GOOGLE_API_FILES "")
foreach (_a_file_nat ${_GOOGLE_API_FILES_NAT})
    FILE(TO_CMAKE_PATH ${_a_file_nat} _a_file)
    LIST(APPEND GOOGLE_API_FILES "${_a_file}")
endforeach ()

#message("API FILES: ${GOOGLE_API_FILES}")
list(LENGTH GOOGLE_API_FILES sources_cnt)
message("Google API sources count: ${sources_cnt}")

if (USE_OS_CERTS)
    message("grpc: USE_OS_CERTS, attempting OS certs")
else ()
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/certs/roots.h" AND DEVMODE)
        message("roots.h exists, not recreating")
    else ()
        message("creating roots.h")
        include(certs/bin2h.cmake)
        bin2h(SOURCE_FILE certs/roots.pem HEADER_FILE certs/roots.h VARIABLE_NAME roots_pem)
    endif ()
    message("grpc: using included certs")
    SET(SPEECH_API_COMPILE_DEFINITIONS GRPC_USE_INCLUDED_CERTS=1)
endif ()

set(SPEECH_API_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/CaptionStream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CaptionStream.h

        ${GOOGLE_API_FILES}
)


target_sources(speech_api_stream PRIVATE ${SPEECH_API_SOURCES})
target_include_directories(speech_api_stream PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(speech_api_stream PRIVATE ${Protobuf_INCLUDE_DIRS})
target_include_directories(speech_api_stream PUBLIC ${GOOGLEAPIS_PATH})

target_link_libraries(speech_api_stream PRIVATE ${GRPC_NAME})
target_link_libraries(speech_api_stream PUBLIC ${PLATFORM_LINK_LIBRARIES})

target_compile_definitions(speech_api_stream PRIVATE ${SPEECH_API_COMPILE_DEFINITIONS})