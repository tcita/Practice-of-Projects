#include "english_assistance/config.h"
#include "english_assistance/util.h"

namespace english_assistance {
    std::vector<std::string> config::readBannedWords() {
        return util::split(util::readFile("./config/bannedWords.txt"), '\n');
    }

    std::string config::readLanguageType() {
        return util::readFile("./config/locale.txt");
    }

    void config::writeLanguageType(const std::string &languageType) {
        util::writeFile("./config/locale.txt", languageType);
    }
}