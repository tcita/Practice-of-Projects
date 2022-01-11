#include "Config.h"
#include "Solution.h"
#include "Strings.h"

std::vector<std::string> Config::readBannedWords()
{
  return Strings::splitString(Solution::readFile("./config/bannedWords.txt"), '\n');
}

std::string Config::readLanguageType()
{
  return Solution::readFile("./config/locale.txt");
}

void Config::writeLanguageType(std::string languageType)
{
  Solution::writeFile("./config/locale.txt", languageType);
}
