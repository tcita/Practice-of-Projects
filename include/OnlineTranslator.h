#ifndef ONLINE_TRANSLATOR_H
#define ONLINE_TRANSLATOR_H

#include <string>

// Get translate by https request
namespace OnlineTranslator {
    std::string translate(const std::string &input, const std::string &destLanguageType, const std::string &srcLanguageType="auto");
};

#endif
