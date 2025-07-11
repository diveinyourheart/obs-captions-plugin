#ifndef OBS_GOOGLE_CAPTION_PLUGIN_WORDREPLACER_H
#define OBS_GOOGLE_CAPTION_PLUGIN_WORDREPLACER_H

#include "string"
#include <vector>
#include <regex>
#include <QString>

using namespace std;

class WordReplaxement {
private:
    string type;
    string from;
    string to;
public:
    WordReplaxement (const string &type, const string &from, const string &to) : type(type), from(from), to(to) {}

    bool operator==(const WordReplaxement &other) const {
        return type == other.type && from == other.from && to == other.to;
    }

    bool operator!=(const WordReplaxement &other) const {
        return !(*this == other);
    }

    [[nodiscard]] const string &get_type() const {
        return type;
    }
    [[nodiscard]] const string &get_from() const {
        return from;
    }
    [[nodiscard]] const string &get_to() const {
        return to;
    }
    friend class Replacer;
};

class Rep {
    private:
    bool use_text;
    std::regex reg;
    string reg_to;
    QString text_from;
    QString text_to;
    bool text_case_sensitive;
    public:
    Rep(const regex &reg, const string &to) :use_text(false), reg(reg), reg_to(to) {}
    Rep(const string &from, const string &to,bool case_sensitive):use_text(true),text_from(QString::fromStdString(from)),text_to(QString::fromStdString(to)),
    text_case_sensitive(case_sensitive){}
    string replace(const string &input) const {
        if (use_text) {
            if (text_from.isEmpty()) {
                return input;
            }

            if (text_case_sensitive)
                return QString::fromStdString(input).replace(text_from,text_to,Qt::CaseSensitive).toStdString();
            return QString::fromStdString(input).replace(text_from,text_to, Qt::CaseInsensitive).toStdString();
        }
        return std::regex_replace(input, reg, reg_to);
    }
};

class Replacer {
    std::vector<Rep> regs;
    public:
    Replacer(const vector<WordReplaxement> &replacements, bool ignore_invalid) {
        addReps(replacements, ignore_invalid);
    }

    bool has_replacements() const {
        return !regs.empty();
    }

    string replace(const string &input) const {
        string res(input);
        for (const auto &rep : regs) {
            res = rep.replace(res);
        }
        return res;
    }

    private:
    void set_replacements(const vector<WordReplaxement> &replacements, bool ignore_invalid) {
        addReps(replacements, ignore_invalid);
    }
    void addReps(const vector<WordReplaxement> &replacements, bool ignore_invalid) {
        for (auto &rep : replacements) {
            if (rep.from.empty())
                continue;
            try {
                if (rep.type == "text_case_sensitive") {
                    regs.emplace_back(rep.from,rep.to,true);
                }else if (rep.type == "text_case_insensitive") {
                    regs.emplace_back(rep.from,rep.to,false);
                }else if (rep.type == "regex_case_sensitive") {
                    regs.emplace_back(regex(rep.from),rep.to);
                }else if (rep.type == "regex_case_insensitive") {
                    regs.emplace_back(regex(rep.from,regex::icase),rep.to);
                }else {
                    throw string("invalid replacement type: "+rep.type);
                }
            }catch (...) {
                if (!ignore_invalid) {
                    throw;
                }
            }
        }
    }

    void addRepsRegex(const vector<WordReplaxement> &replacements, bool ignore_invalid) {
        std::regex escape_reg(R"([/|[\]{}()\\^$*+?.])");

        for (auto &rep : replacements) {
            try {
                if (rep.type == "text_case_sensitive") {
                    string escaped = std::regex_replace(rep.from, escape_reg, "\\$0");
                    regs.emplace_back(regex(escaped),rep.to);
                } else if (rep.type == "text_case_insensitive") {
                    string escaped = std::regex_replace(rep.from, escape_reg, "\\$0");
                    regs.emplace_back(regex(escaped,regex::icase),rep.to);
                } else if (rep.type == "regex_case_sensitive") {
                    regs.emplace_back(regex(rep.from),rep.to);
                } else if (rep.type == "regex_case_insensitive") {
                    regs.emplace_back(regex(rep.from,regex::icase),rep.to);
                } else {
                    throw string("invalid replacement type: " + rep.type);
                }
            }
            catch (...) {
                if (!ignore_invalid)
                    throw;
            }
        }
    }
};

#endif //OBS_GOOGLE_CAPTION_PLUGIN_WORDREPLACER_H
