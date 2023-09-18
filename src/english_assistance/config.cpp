#include "english_assistance/config.h"
#include "english_assistance/util.h"

namespace english_assistance {
    namespace config {
        std::vector<std::string> readBannedWords() {
            return util::split(util::readFile(BANNED_WORDS_PATH), '\n');
        }

        std::string readLanguageType() {
            return util::readFile(LOCALE_PATH);
        }

        void writeLanguageType(const std::string &languageType) {
            util::writeFile(LOCALE_PATH, languageType);
        }
    }
}