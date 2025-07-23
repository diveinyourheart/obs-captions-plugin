#ifndef OBS_GOOGLE_CAPTION_PLUGIN_STRINGUTILS_H
#define OBS_GOOGLE_CAPTION_PLUGIN_STRINGUTILS_H

#include <QVector>
#include <QStringList>
#include <QTextBoundaryFinder>
#include <QRegularExpression>
#include "CaptionResultHandler.h"

static void string_capitalization(string &line, const CapitalizationType capitalization) {
    if (capitalization == CAPITALIZATION_ALL_CAPS) {
        std::transform(line.begin(),line.end(),line.begin(),[](const unsigned char c){return std::toupper(c);});
    }else if (capitalization == CAPITALIZATION_ALL_LOWERCASE) {
        std::transform(line.begin(),line.end(),line.begin(),[](const unsigned char c){return std::tolower(c);});
    }
}

static void lstrip(string &line) {
    line.erase(line.begin(),std::find_if(line.begin(),line.end(),[](unsigned char c){return !std::isspace(c);}));
}

static bool isAscii(const string &text) {
    for (const auto c : text) {
        if (static_cast<unsigned char>(c) > 127) {
            return false;
        }
    }
    return true;
}

static void splitSmallest(QVector<QString> &out_chars, const QString &word) {
    QTextBoundaryFinder test(QTextBoundaryFinder::Grapheme,word);
    int start = 0;
    while (test.toNextBoundary() != -1 &&test.position() <= word.length()) {
        out_chars.push_back(word.mid(start,test.position()-start));
        start = test.position();
    }

    for (int i = 0;i<out_chars.length();i++){}
}

static void split_into_lines_unicode_ish(vector<string> &out_lines, const string &text, const uint max_line_length) {
    QString qtext = QString::fromStdString(text).simplified();
    static QRegularExpression expression = QRegularExpression("\\s+");
    QStringList words = qtext.split(expression);
    uint cnt = 0;
    QString line;
    for (auto word : words) {
        int new_len = line.size() + (line.isEmpty() ? 0 : 1) + word.size();
        if (new_len <= max_line_length) {
            if (!line.isEmpty())
                line.append(' ');
            line.append(word);
        }else {
            if (word.length() > max_line_length) {
                if (!line.isEmpty()) {
                    if (line.length() + 2 <= max_line_length) {
                        line.append(' ');
                    }else {
                        out_lines.push_back(line.toStdString());
                        line = "";
                    }
                }

                QVector<QString> gms;
                splitSmallest(gms, word);
                for (auto i:gms) {
                    if (line.length() + i.length() <= max_line_length) {
                        line.append(i);
                    }else {
                        out_lines.push_back(line.toStdString());
                        line = i;
                    }
                }
            }else {
                if (!line.isEmpty())
                    out_lines.push_back(line.toStdString());
                line = word;
            }
        }
    }

}

static void split_into_lines_ascii(vector<string> &out_lines, const string &text, const uint max_line_length) {
    istringstream stream(text);
    string word;
    string line;
    while (getline(stream,word,' ')) {
        if (word.empty())
            continue;
        int new_len = line.size() + (line.empty() ? 0 : 1) + word.size();
        if (new_len <= max_line_length) {
            if (!line.empty())
                line.append(" ");
            line.append(word);
        }else {
            if (word.length() > max_line_length) {
                if (!line.empty()) {
                    if (line.length() + 2 <= max_line_length) {
                        line.append(" ");
                    }else {
                        out_lines.push_back(line);
                        line = "";
                    }
                }

                for (auto i:word) {
                    if (line.length() < max_line_length) {
                        line.push_back(i);
                    }else {
                        out_lines.push_back(line);
                        line = i;
                    }
                }
            }else {
                if (!line.empty())
                    out_lines.push_back(line);
                line = word;
            }
        }
    }
}

static void split_into_lines(vector<string> &out_lines, const string &text, const uint max_line_length) {
    if (!isAscii(text)) {
        split_into_lines_unicode_ish(out_lines, text, max_line_length);
        return;
    }
    split_into_lines_ascii(out_lines, text, max_line_length);
}

static void join_strings(const vector<string> &lines, const string &joiner, string &output) {
    for (const string &line : lines) {
        if (!output.empty())
            output.append(joiner);
        output += line;
    }
}

#endif //OBS_GOOGLE_CAPTION_PLUGIN_STRINGUTILS_H
