#ifndef STRINGS_H
#define STRINGS_H

#include <vector>
#include <string>

namespace Strings
{
  // Split string by given char, return vector of string
  std::vector<std::string> splitString(const std::string &string, const char c);
};

#endif
