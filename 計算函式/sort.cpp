#include<vector>
#include<iostream>
#include <unordered_map>
#include <map>
#include<string>
#include<algorithm>

#include<unordered_set>
using namespace std;


class Solution {
public:
    //string paragraph:��̎���Ӣ������     vector<string>& banned ���{��yӋ�Ć���
    void Wordfrequency(string paragraph, vector<string>& banned) {

        unordered_set<string> b;
       
        //�l�����F�ĺ����˜�
        const int count = 3;
        //�l�����F�Ć���
        unordered_map<string,int> maxw;

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

                    //�z���Ƿ���ֽ������F
                    if (str2cnt[curr] >= count)
                    {
                        maxw.insert(pair<string, int>(curr,str2cnt[curr]));
                    }
                }
                //�Y����һ�����ֵĽ���,��ʽ��curr���
                curr = "";
            }
        }


         //����ĶεĽYβ���֛]�з���ĸ�Yβ,��"I hate the sunlight" ,Ҫ�~��ӑՓ,���Eֻ��Ҫ�����}����һ�μ���
        if (curr.size() > 0)
        {
            
            if (b.find(curr) == b.end())
            {
                ++str2cnt[curr];
                if (str2cnt[curr] >= count)
                {
                    maxw.insert(pair<string, int>(curr, str2cnt[curr]));
                }
            }
            curr = "";
        }

        
        
        
        //�Y��ݔ�� 
        cout << "�������F�Ć��~�� "<<"\n\n";

              for (auto& t : maxw) {

            cout << t.first << " " << t.second <<"��"<< endl;

        }

        cout << '\n'<<"���ֳ��F�l��\n";
        
        for (auto& t : str2cnt) {

            cout << t.first << " " << t.second << "��" << endl;

        }


       
    }
};
int main() {
    //�yԇ
    vector<string>banned = {"hit"};
    Solution s;
  s.Wordfrequency
    ("Honeybees are characterised by their ability to produce liquefied sugar (honey) and a propensity to construct colonial nests using wax, two tasks that necessitate a significant level of social integration among members. As a result, they maintain strict divisions of labour, based on sex, with all males functioning as drones to fertilize and care for the eggs, and all females, with the exception of the single fertile queen, responsible for fetching nectar for the colony��s progeny. In addition, honeybees have devised a sophisticated system of communication to relay important information from member to member.", banned);


}