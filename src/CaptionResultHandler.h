#ifndef CPPTESTING_CAPTIONRESULTHANDLER_H
#define CPPTESTING_CAPTIONRESULTHANDLER_H

#include <utility>
#include <string>
#include <CaptionStream.h>
#include "WordReplacer.h"

enum CapitalizationType {
    CAPITALIZATION_NORMAL = 0,
    CAPITALIZATION_ALL_CAPS = 1,
    CAPITALIZATION_ALL_LOWERCASE = 2
};

class DefaultReplacer {
    Replacer text_replacer;
    std::vector<string> default_replacements;
    std::vector<WordReplacement> manual_replacements;
    public:
    const std::vector<WordReplacement>& user_replacements() const {
        return manual_replacements;
    }

    bool has_replacements() const {
        return text_replacer.has_replacements();
    }

    DefaultReplacer(const vector<string>& default_replacements,
        const std::vector<WordReplacement>& manual_replacements) : default_replacements(default_replacements),
    manual_replacements(manual_replacements),
    text_replacer(Replacer(combineWordReps(wordRepsFromStrs("regex_case_insensitive",default_replacements),manual_replacements),true))
    {}
    bool operator==(const DefaultReplacer &other) const {
        return manual_replacements == other.manual_replacements &&
            default_replacements == other.default_replacements;
    }
    bool operator!=(const DefaultReplacer &other) const {
        return !(*this == other);
    }
    const Replacer& get_replacer() const {
        return text_replacer;
    }
};

struct CaptionFormatSettings {
    uint caption_line_length;
    uint caption_line_count;
    CapitalizationType capitalization_type;
    bool caption_insert_newlines;
    bool caption_insert_punctuation;

    bool caption_timeout_enabled;
    double caption_timeout_seconds;
    DefaultReplacer default_replacer;
    CaptionFormatSettings(
        uint caption_line_length,
        uint caption_line_count,
        CapitalizationType capitalization_type,
        bool caption_insert_newlines,
        bool caption_insert_punctuation,
        const DefaultReplacer& default_replacer,
        bool caption_timeout_enabled,
        double caption_timeout_seconds
        ):
        caption_line_length(caption_line_length),
        caption_line_count(caption_line_count),
        capitalization_type(capitalization_type),
        caption_insert_newlines(caption_insert_newlines),
        caption_insert_punctuation(caption_insert_punctuation),
        caption_timeout_enabled(caption_timeout_enabled),
        caption_timeout_seconds(caption_timeout_seconds),
        default_replacer(default_replacer) {
    }

    void print(const char* line_prefix = "") const {
        printf("%sCaptionFormatSettings\n", line_prefix);
        printf("%s  caption_line_length: %d\n", line_prefix, caption_line_length);
        printf("%s  caption_line_count: %d\n", line_prefix, caption_line_count);
        printf("%s  capitalization_type: %d\n", line_prefix, capitalization_type);
        printf("%s  caption_insert_newlines: %d\n", line_prefix, caption_insert_newlines);
        printf("%s  caption_insert_punctuation: %d\n", line_prefix, caption_insert_punctuation);
        printf("%s  user_replacements: %lu\n", line_prefix, default_replacer.user_replacements().size());
        for (auto &word:default_replacer.user_replacements())
            printf("%s      %s '%s' -> '%s'\n",
                line_prefix,word.get_type().c_str(),word.get_from().c_str(),word.get_to().c_str());
    }

    bool operator==(const CaptionFormatSettings &other) const {
        return caption_line_count == other.caption_line_count &&
            capitalization_type == other.capitalization_type &&
                caption_insert_newlines == other.caption_insert_newlines &&
                    caption_insert_punctuation == other.caption_insert_punctuation&&
                        caption_timeout_enabled == other.caption_timeout_enabled &&
                            caption_timeout_seconds == other.caption_timeout_seconds &&
                                default_replacer == other.default_replacer&&
                                        caption_line_length == other.caption_line_length;
    }

    bool operator!=(const CaptionFormatSettings &other) const {
        return !(*this == other);
    }
};

struct OutputCaptionResult {
    CaptionResult caption_result;
    bool interrupted;
    string clean_caption_text;

    vector<string> output_lines;
    string output_line;

    OutputCaptionResult(const CaptionResult &caption_result,const bool interrupted):
    caption_result(caption_result),interrupted(interrupted) {}
};

class CaptionResultHandler {
    CaptionFormatSettings settings;

    public:
    explicit CaptionResultHandler(CaptionFormatSettings settings);

    shared_ptr<OutputCaptionResult> prepare_caption_output(
        const CaptionResult &caption_result,
        const bool fillup_with_previous,
        const bool insert_newlines,
        const bool punctuation,
        const uint line_length,
        const uint targeted_line_count,
        const CapitalizationType capitalization_type,
        const bool interrupted,
        const std::vector<std::shared_ptr<OutputCaptionResult>> &result_history
    );
};

#endif //CPPTESTING_CAPTIONRESULTHANDLER_H
