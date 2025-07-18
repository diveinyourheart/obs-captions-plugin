#ifndef OBS_GOOGLE_CAPTION_PLUGIN_CAPTION_TRANSCRIPT_WRITER_H
#define OBS_GOOGLE_CAPTION_PLUGIN_CAPTION_TRANSCRIPT_WRITER_H

#include "log.c"
#include <QDir>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include "stringutils.h"
#include "ui/uiutils.h"

using ResultTup = std::tuple<
    std::chrono::steady_clock::time_point,
    std::chrono::steady_clock::time_point,
    std::string,
    bool
    >;

using ResultQueue = std::deque<ResultTup>;

const string NEWLINE_STR="\r\n";

using MonoTP = std::chrono::steady_clock::time_point;
using MonoDur = std::chrono::steady_clock::duration;

QFileInfo find_unused_filename(
    const QFileInfo &output_directory,
    const QString &basename,
    const QString &extension,
    const int tries
) {
    QString cnt_str("");
    for (int i=0; i<tries; i++) {
        auto file_name = QString("%1%2.%3").arg(basename,cnt_str,extension);
        QFileInfo file_candidate(QDir(output_directory.absoluteFilePath()).absoluteFilePath(file_name));
        if (!file_candidate.exists())
            return file_candidate;
        cnt_str = QString("_%1").arg(i+1);
    }
    throw string("wtf");
}

struct UseTranscriptSettings {
    string name_type;
    string filename_custom;
    string filename_custom_exists;
    string file_basename;
};

UseTranscriptSettings build_use_settings(const TranscriptOutputSettings &transcript_settings, const string &target_name) {
    string name_type;
    string name_custom;
    string name_exists;
    string basename;

    if (target_name == "stream") {
        name_type = transcript_settings.streaming_filename_type;
        name_custom = transcript_settings.streaming_filename_custom;
        name_exists = transcript_settings.streaming_filename_exists;
        basename = "streaming_transcript_";
    } else if (target_name == "recording") {
        name_type = transcript_settings.recording_filename_type;
        name_custom = transcript_settings.recording_filename_custom;
        name_exists = transcript_settings.recording_filename_exists;
        basename = "recording_transcript_";
    } else if (target_name == "virtualcam") {
        name_type = transcript_settings.virtualcam_filename_type;
        name_custom = transcript_settings.virtualcam_filename_custom;
        name_exists = transcript_settings.virtualcam_filename_exists;
        basename = "virtualcam_transcript_";
    } else
        throw string("unsupported target name: " + target_name);

    return UseTranscriptSettings{
        name_type,
        name_custom,
        name_exists,
        basename,
    };
}

QFileInfo find_transcript_filename_custom(
    const TranscriptOutputSettings &transcript_settings,
    const UseTranscriptSettings &rel,
    const QFileInfo &output_directory,
    const std::chrono::system_clock::time_point &started_at,
    const int tries,
    bool &out_overwrite
) {
    if (rel.filename_custom.empty())
        throw string("custom filename chosen but no filename given");

    if (rel.filename_custom_exists == "overwrite")
        out_overwrite = true;
    auto file = QFileInfo(QDir(output_directory.absoluteFilePath()).absoluteFilePath(QString::fromStdString(rel.filename_custom)));
    if (!file.exists())
        return file;
    if (rel.filename_custom_exists == "overwrite") {
        out_overwrite = true;
        return file;
    }
    if (rel.filename_custom_exists == "append") {
        out_overwrite = false;
        return file;
    }
    if (rel.filename_custom_exists == "skip") {
        throw string("custom transcript file exists already, skipping: " + file.absoluteFilePath().toStdString());
    }
    throw string("custom transcript file exists already, invalid exists option: " + rel.filename_custom_exists);
}

QFileInfo find_transcript_filename_datetime(
    const TranscriptOutputSettings &transcript_settings,
    const UseTranscriptSettings &rel,
    const QFileInfo &output_directory,
    const std::chrono::system_clock::time_point &started_at,
    const int tries,
    const string &extension
) {
    std::ostringstream oss;
    time_t start_at_t = std::chrono::system_clock::to_time_t(started_at);
    oss<<std::put_time(std::localtime(&start_at_t),"%Y-%m-%d_%H-%M-%S");
    auto started_at_str = oss.str();

    string basename = rel.file_basename + started_at_str;
    return find_unused_filename(output_directory,QString::fromStdString(basename),QString::fromStdString(extension),tries);
}

QFileInfo find_transcript_filename_recording(
    const TranscriptOutputSettings &transcript_settings,
    const QFileInfo &output_directory,
    const std::chrono::system_clock::time_point &started_at,
    const int tries,
    const string &extension,
    const bool try_url
) {
    OBSOutput output = obs_frontend_get_recording_output();
    obs_output_release(output);
    OBSData settings = obs_output_get_settings(output);
    obs_data_release(settings);

    string recording_path = obs_data_get_string(settings, "path");
    if (recording_path.empty()) {
        if (!try_url)
            throw string("couldn't get recording path");
        recording_path = obs_data_get_string(settings, "url");
        if (recording_path.empty())
            throw string("couldn't get recording url");
        info_log("find_transcript_filename_recording no recording path, using url");
    }

    const auto recording_file = QFileInfo(QString::fromStdString(recording_path));
    const QString basename = recording_file.completeBaseName();

    if (basename.isEmpty())
        throw string("couldn't get recording basename");

    return find_unused_filename(output_directory,basename,QString::fromStdString(extension),tries);
}

#endif //OBS_GOOGLE_CAPTION_PLUGIN_CAPTION_TRANSCRIPT_WRITER_H
