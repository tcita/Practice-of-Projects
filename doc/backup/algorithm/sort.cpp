#include <deque>
#include<iostream>
#include <unordered_set>
#include <unordered_map>
#include<vector>
#include <map>
#include<string>
#include<algorithm>
#include <fstream>
using namespace std;


class Solution {
public:
    string readfile() {
        ifstream ifs("testfile.txt");

        string content
        ((istreambuf_iterator<char>(ifs)),
            (istreambuf_iterator<char>()));
        return  content;
    }


public:
    //string paragraph:待處理的英文文章     vector<string>& banned 不納入統計的單字
    string Wordfrequency(string paragraph, vector<string>& banned) {
        string re;
        unordered_set<string> b;

        //頻繁出現的衡量標準
        const int count = 3;
        //頻繁出現的單字
        unordered_map<string, int> maxw;

        //curr:當前考察的單字
        string curr;
        //頻繁出現的單字出現次數

        //頻率的結果,使用map儲存後結果會按字母表排序
        map<string, int> str2cnt;


        for (string bb : banned)
        {
            b.insert(bb);
        }
        for (char c : paragraph)
        {
            if (isalpha(c))
            {
                //tolower將大寫字母轉換為小寫字母
                curr += tolower(c);
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

        cout << '\n' << "單字出現頻率\n";

        for (auto& t : str2cnt) {

            //檢查是否單字經常出現

            re += t.first + " " + to_string(t.second) + "次";
            cout << t.first << " " << t.second << "次";

            if (t.second >= count)
            {

                re += "▲";
                cout << "▲";
            }
            re += "\n";
            cout << endl;
        }

        return re;

    }
    void write(string s) {
        //不存在則新建
        ofstream fout;
        fout.open("out.txt");

        fout << s;
        fout.close();
    }


};
int main() {
    //測試
    vector<string>banned = { "a","the","I" };
    Solution s;
    //s.Wordfrequency
    //  ("Honeybees are characterised by their ability to produce liquefied sugar (honey) and a propensity to construct colonial nests using wax, two tasks that necessitate a significant level of social integration among members. As a result, they maintain strict divisions of labour, based on sex, with all males functioning as drones to fertilize and care for the eggs, and all females, with the exception of the single fertile queen, responsible for fetching nectar for the colony’s progeny. In addition, honeybees have devised a sophisticated system of communication to relay important information from member to member.", banned);
    string str = s.readfile();

    s.write(s.Wordfrequency(str, banned));

}