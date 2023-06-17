#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace english_assistance {
    const std::filesystem::path BANNED_WORDS_PATH = "config/banned_words.cfg";
    const std::filesystem::path LOCALE_PATH = "config/locale.cfg";

    // Get the config text file from project config folder
    namespace config {
        std::vector<std::string> readBannedWords();
        std::string readLanguageType();
        void writeLanguageType(const std::string &languageType);
    };
}