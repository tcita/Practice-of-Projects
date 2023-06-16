#pragma once

#include <string>

namespace english_assistance {
    namespace translate {
        // translate a string from a language to another language
        std::string translate(const std::string &input, const std::string &destLanguageType, const std::string &srcLanguageType="auto");
    };
}