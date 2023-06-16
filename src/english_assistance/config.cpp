#include "english_assistance/config.h"
#include "english_assistance/util.h"

namespace english_assistance {
    std::vector<std::string> config::readBannedWords() {
        return util::split(util::readFile(BANNED_WORDS_PATH), '\n');
    }

    std::string config::readLanguageType() {
        return util::readFile(LOCALE_PATH);
    }

    void config::writeLanguageType(const std::string &languageType) {
        util::writeFile(LOCALE_PATH, languageType);
    }
}