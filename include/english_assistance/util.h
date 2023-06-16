#pragma once

#include <vector>
#include <string>

namespace english_assistance {
    namespace util {
        // Split string by given char, return vector of string
        std::vector<std::string> split(const std::string &string, const char c);
        // Count the word appear frequency of the article, the given banned words will be ignored
        std::vector<std::pair<std::string,int>> wordFrequency(const std::string &article, const std::vector<std::string> &bannedWords);
        // Read content of a file
        std::string readFile(const std::string &filePath);
        // Wirte content to a file
        void writeFile(const std::string &filePath, const std::string &content);
    };
}