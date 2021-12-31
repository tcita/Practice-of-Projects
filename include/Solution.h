#ifndef SOLUTION_H
#define SOLUTION_H

#include<vector>
#include<string>

namespace Solution {
  // Count the word appear frequency of the article, the given banned words will be ignored
  std::vector<std::pair<std::string,int>> wordFrequency(const std::string &article, std::vector<std::string> &bannedWords);
  // Read content of a file
  std::string readFile(const std::string &filePath);
  // Wirte content to a file
  void writeFile(const std::string &filePath, const std::string &content);
  // Split string by given char, return vector of string
  std::vector<std::string> splitString(const std::string &string, const char c);
};

#endif
