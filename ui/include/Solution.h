#ifndef SOLUTION_H
#define SOLUTION_H

#include<vector>
#include<string>

class Solution {
public:
  //string paragraph:待處理的英文文章     vector<string>& banned 不納入統計的單字
  static std::string wordFrequency(const std::string &paragraph, std::vector<std::string> &bannedWords);
  static std::string readFile(const std::string &filePath);
  static void writeFile(const std::string &filePath, const std::string &content);
};

#endif
