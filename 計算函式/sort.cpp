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
    //string paragraph:��̎���Ӣ������     vector<string>& banned ���{��yӋ�Ć���
    string Wordfrequency(string paragraph, vector<string>& banned) {
        string re;
        unordered_set<string> b;

        //�l�����F�ĺ����˜�
        const int count = 3;
        //�l�����F�Ć���
        unordered_map<string, int> maxw;

        //curr:��ǰ����Ć���
        string curr;
        //�l�����F�Ć��ֳ��F�Δ�

        //�l�ʵĽY��,ʹ��map������Y��������ĸ������
        map<string, int> str2cnt;


        for (string bb : banned)
        {
            b.insert(bb);
        }
        for (char c : paragraph)
        {
            if (isalpha(c))
            {
                //tolower������ĸ�D�Q��С����ĸ
                curr += tolower(c);
            }
            //���Ų鵽����Ԫ������ĸ�r,ҕ��ǰ��curr��һ������
            else if (curr.size() > 0)
            {
                // ban�����Æ���,  ���µ�ʽ�����ėl���Ǯ�ǰ������ֲ�����Æ���
                if (b.find(curr) == b.end())
                {
                    ++str2cnt[curr];


                }
                //�Y����һ�����ֵĽ���,��ʽ��curr���
                curr = "";
            }
        }


        ////����ĶεĽYβ���֛]�з���ĸ�Yβ,��"I hate the sunlight" ,Ҫ�~��ӑՓ,���Eֻ��Ҫ�����}����һ�μ���
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




        //�Y��ݔ�� 

        //����Ҫ�Ğ���Ҫ��return ���

        cout << '\n' << "���ֳ��F�l��\n";

        for (auto& t : str2cnt) {

            //�z���Ƿ���ֽ������F

            re += t.first + " " + to_string(t.second) + "��";
            cout << t.first << " " << t.second << "��";

            if (t.second >= count)
            {

                re += "��";
                cout << "��";
            }
            re += "\n";
            cout << endl;
        }

        return re;

    }
    void write(string s) {
        //�����ڄt�½�
        ofstream fout;
        fout.open("out.txt");

        fout << s;
        fout.close();
    }


};
int main() {
    //�yԇ
    vector<string>banned = { "a","the","I" };
    Solution s;
    //s.Wordfrequency
    //  ("Honeybees are characterised by their ability to produce liquefied sugar (honey) and a propensity to construct colonial nests using wax, two tasks that necessitate a significant level of social integration among members. As a result, they maintain strict divisions of labour, based on sex, with all males functioning as drones to fertilize and care for the eggs, and all females, with the exception of the single fertile queen, responsible for fetching nectar for the colony��s progeny. In addition, honeybees have devised a sophisticated system of communication to relay important information from member to member.", banned);
    string str = s.readfile();

    s.write(s.Wordfrequency(str, banned));

}