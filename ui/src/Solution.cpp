#include "Solution.h"
#include <deque>
#include<iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include<algorithm>
#include <fstream>

std::string Solution::wordFrequency(const std::string &paragraph, std::vector<std::string> &bannedWords) {
    std::unordered_set<std::string> b;

    //頻繁出現的衡量標準
    const int count = 3;
    //頻繁出現的單字
    std::unordered_map<std::string, int> maxw;

    //curr:當前考察的單字
    std::string curr;
    //頻繁出現的單字出現次數

    //頻率的結果,使用map儲存後結果會按字母表排序
    std::map<std::string, int> str2cnt;


    for (const std::string &bannedWord : bannedWords)
    {
        b.insert(bannedWord);
    }
    for (char c : paragraph)
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
            if (b.find(curr) == b.end())
            {
                ++str2cnt[curr];
            }
            //結束了一個單字的解析,格式化curr為空
            curr = "";
        }
    }


    ////如果文段的結尾單字沒有非字母結尾,如"I hate the sunlight" ,要額外討論,步驟只需要再重複上面一次即可
    //if (curr.size() > 0)
    //{

    //    if (b.find(curr) == b.end())
    //    {
    //        ++str2cnt[curr];
    //        if (str2cnt[curr] >= count)
    //        {
    //            maxw.insert(pair<string, int>(curr, str2cnt[curr]));
    //        }
    //    }
    //    curr = "";
    //}




    //結果輸出

    //可能要改為需要的return 類型

    // std::cout << '\n' << "單字出現頻率\n";
    //
    // for (auto& t : str2cnt) {
    //
    //     //檢查是否單字經常出現
    //
    //     re += t.first + " " + std::to_string(t.second) + "次";
    //     std::cout << t.first << " " << t.second << "次";
    //
    //     if (t.second >= count)
    //     {
    //
    //         re += "▲";
    //         std::cout << "▲";
    //     }
    //     re += "\n";
    //     std::cout << std::endl;
    // }

    std::vector<std::string> result;

    for (auto& t : str2cnt) {

        //檢查是否單字經常出現
        re += t.first + ": " + std::to_string(t.second) + "\n";
    }

    return re;
}

std::string Solution::readFile(const std::string &filePath) {
    // std::ifstream ifs("testfile.txt");
    std::ifstream ifs(filePath);

    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return content;
}

void Solution::writeFile(const std::string &filePath, const std::string &content) {
    //不存在則新建
    std::ofstream fout;
    fout.open(filePath);

    fout << content;

    fout.close();
}
