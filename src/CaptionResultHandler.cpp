#include "CaptionResultHandler.h"
#include "log.h"
#include <sstream>
#include <cctype>
#include <iostream>
#include <vector>
#include <utils.h>
#include "stringutils.h"

shared_ptr<OutputCaptionResult> CaptionResultHandler::prepare_caption_output(const CaptionResult &caption_result, const bool fillup_with_previous,
    const bool insert_newlines, const bool punctuation, const uint line_length, const uint targeted_line_count,
    const CapitalizationType capitalization_type, const bool interrupted, const std::vector<std::shared_ptr<OutputCaptionResult> > &result_history) {
    shared_ptr<OutputCaptionResult> output_result = make_shared<OutputCaptionResult>(caption_result, interrupted);

    try {
        const uint max_length = targeted_line_count * line_length;
        string cleaned_line = caption_result.caption_text;
        if (settings.default_replacer.has_replacements()) {
            try {
                string tmp = settings.default_replacer.get_replacer().replace(caption_result.caption_text);

                if (caption_result.caption_text != tmp) {
                    info_log("modified string '%s' -> '%s'", caption_result.caption_text.c_str(), tmp.c_str());
                    cleaned_line = tmp;
                }
            }catch (const std::exception &e) {
                error_log("string replacement error %s: '%s'", e.what(),caption_result.caption_text.c_str());
            }catch (...) {
                error_log("string replacement error '%s'", caption_result.caption_text.c_str());
            }
        }
        lstrip(cleaned_line);
        output_result->clean_caption_text = cleaned_line;

        vector<string> all_lines;
        if (fillup_with_previous) {
            string filled_line = cleaned_line;
            if (punctuation && capitalization_type == CAPITALIZATION_NORMAL && !filled_line.empty() && isascii(filled_line[0]))
                filled_line[0] = toupper(filled_line[0]);
            if (filled_line.size() < max_length && !result_history.empty()) {
                for (auto iter = result_history.begin(); iter != result_history.end(); ++iter) {
                    if (!*iter)
                        break;
                    if (!(*iter)->caption_result.final)
                        break;
                    if (settings.caption_timeout_enabled) {
                        double secs_since_last = std::chrono::duration_cast<std::chrono::duration<double>>
                        (std::chrono::steady_clock::now() - (*iter)->caption_result.received_at).count();
                        if (secs_since_last > settings.caption_timeout_seconds) {
                            debug_log("not filling, too old %f >= %f", secs_since_last,settings.caption_timeout_seconds);
                            break;
                        }
                    }

                    if (punctuation)
                        filled_line.insert(0, ". ");
                    else
                        filled_line.insert(0, " ");
                    filled_line.insert(0, (*iter) -> clean_caption_text);

                    if (punctuation && capitalization_type == CAPITALIZATION_NORMAL && !filled_line.empty() && isascii(filled_line[0]))
                        filled_line[0] = toupper(filled_line[0]);
                    if (filled_line.size() >= max_length)
                        break;
                }
            }
            string_capitalization(filled_line,capitalization_type);
            split_into_lines(all_lines, filled_line,line_length);
        }else {
            string_capitalization(cleaned_line,capitalization_type);
            split_into_lines(all_lines, cleaned_line,line_length);
        }

        const uint use_lines_cnt = all_lines.size() > targeted_line_count ? targeted_line_count : all_lines.size();
        output_result->output_lines.insert(output_result->output_lines.end(),all_lines.end()-use_lines_cnt,all_lines.end());

        if (!output_result->output_lines.empty()) {
            string join_char = insert_newlines ? "\n" : " ";
            join_strings(output_result->output_lines, join_char, output_result->output_line);
        }

        return output_result;
    }catch (string &e) {
        info_log("couldn't parse caption message. Error: '%s'. Message: '%s'", e.c_str(),caption_result.caption_text.c_str());
        return nullptr;
    }catch (...) {
        info_log("couldn't parse caption message. Messsage: '%s'", caption_result.caption_text.c_str());
        return nullptr;
    }
}

CaptionResultHandler::CaptionResultHandler(CaptionFormatSettings settings) : settings(settings) {}

