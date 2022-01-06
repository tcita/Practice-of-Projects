#include "Strings.h"
#include <sstream>

std::vector<std::string> Strings::splitString(const std::string &string, const char c) {
  std::istringstream stringStream = std::istringstream(string);
  std::vector<std::string> strings;
  std::string temp;
  while(std::getline(stringStream, temp, c))
  {
    if(temp != " ")
    {
      strings.push_back(temp);
    }
  }

  return strings;
}
