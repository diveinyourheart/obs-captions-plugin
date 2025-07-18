#ifndef OBS_GOOGLE_CAPTION_PLUGIN_CAPTIONPLUGINSETTINGS_H
#define OBS_GOOGLE_CAPTION_PLUGIN_CAPTIONPLUGINSETTINGS_H

#include "SourceCaptioner.h"
struct CaptionPluginSettings {
    bool enabled;
    SourceCaptionerSettings source_cap_settings;
    CaptionPluginSettings(bool enabled, SourceCaptionerSettings &source_cap_settings):
    enabled(enabled),source_cap_settings(source_cap_settings)
    {}

    bool operator==(const CaptionPluginSettings &other) const {
        return enabled == other.enabled && source_cap_settings == other.source_cap_settings;
    }

    bool operator!=(const CaptionPluginSettings &other) const {
        return !(*this == other);
    }

    void print(const char *line_prefix = "") {
        printf("%sCaptionPluginSettings\n", line_prefix);
        printf("%senabled: %d\n", line_prefix, enabled);
        source_cap_settings.print((string(line_prefix) + "").c_str());
    }
};

#endif //OBS_GOOGLE_CAPTION_PLUGIN_CAPTIONPLUGINSETTINGS_H
