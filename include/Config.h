#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

// Get the config text file from project config folder
namespace Config {
    std::vector<std::string> readBannedWords();
    std::string readLanguageType();
    void writeLanguageType(std::string languageType);
};

#endif
