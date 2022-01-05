#include "Config.h"
#include "Solution.h"
#include "Strings.h"

std::vector<std::string> Config::getBannedWords()
{
  return Strings::splitString(Solution::readFile("./config/bannedWords.txt"), '\n');
}
