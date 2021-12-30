#ifndef SOLUTION_H
#define SOLUTION_H

#include<vector>
#include<string>

class Solution {
public:
  // Count the word appear frequency of the article, the given banned words will be ignored
  static std::vector<std::string> wordFrequency(const std::string &article, std::vector<std::string> &bannedWords);
  // Read content of a file
  static std::string readFile(const std::string &filePath);
  // Wirte content to a file
  static void writeFile(const std::string &filePath, const std::string &content);
  // Split string by given char, return vector of string
  static std::vector<std::string> splitString(const std::string &string, const char c);
};

#endif
