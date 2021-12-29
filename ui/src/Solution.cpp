#include "Solution.h"
#include <deque>
#include<iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include<algorithm>
#include <fstream>

std::string Solution::wordFrequency(const std::string &article, std::vector<std::string> &bannedWords) {
    //頻繁出現的衡量標準
    const int count = 3;
    //頻繁出現的單字
    std::unordered_map<std::string, int> maxw;

    //curr:當前考察的單字
    std::string curr;
    //頻繁出現的單字出現次數

    //頻率的結果,使用map儲存後結果會按字母表排序
    std::map<std::string, int> str2cnt;


    std::unordered_set<std::string> bannedWordSet;
    for (const std::string &bannedWord : bannedWords)
    {
        bannedWordSet.insert(bannedWord);
    }
    for (char c : article)
    {
        if (std::isalpha(c))
        {
            //tolower將大寫字母轉換為小寫字母
            curr += std::tolower(c);
        }
        //當排查到的字元不是字母時,視為前面curr是一個單字
        else if (curr.size() > 0)
        {
            // ban掉禁用單字,  以下等式成立的條件是當前考察單字不為禁用單字
            if (bannedWordSet.find(curr) == bannedWordSet.end())
            {
                ++str2cnt[curr];
            }
            //結束了一個單字的解析,格式化curr為空
            curr = "";
        }
    }

    std::string result;
    for (auto& t : str2cnt) {
        result += t.first + ": " + std::to_string(t.second) + "\n";
    }

    return result;
}

std::string Solution::readFile(const std::string &filePath)
{
  std::ifstream ifs(filePath);
  if(!ifs.is_open())
  {
    std::cerr << "Error on Solution::readFile(const std::string &filePath)\nFile \"" << filePath << "\" not found!";
  }
  std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
  return content;
}

void Solution::writeFile(const std::string &filePath, const std::string &content)
{
  // Create if file is not exist
  std::ofstream fout;
  fout.open(filePath);

  fout << content;

  fout.close();
}
