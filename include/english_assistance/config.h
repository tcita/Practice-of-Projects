#pragma once

#include <string>
#include <vector>

namespace english_assistance {
    // Get the config text file from project config folder
    namespace config {
        std::vector<std::string> readBannedWords();
        std::string readLanguageType();
        void writeLanguageType(const std::string &languageType);
    };
}