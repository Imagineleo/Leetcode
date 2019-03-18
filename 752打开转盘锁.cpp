#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

class Solution{

    public:
    int openLock(vector<string>& deadends,string target){
        string beginStr="0000";
        set<string>dead(deadends.begin(),deadends.end());
        set<string>visited;
        char flag_1 = '9' +1;
        char flag_2 = '0' -1;
        int min_length = INT_MAX;

        visited.insert(beginStr);
        queue<pair<int,string>>que;
        que.push({'0',beginStr});
        if(dead.count("0000"))
        return -1;

        while(!que.empty())
        {
            auto tmp = que.front();
            que.pop();
            if(tmp.second == target && tmp.first<min_length){
                min_length=tmp.first;

            }
            if(tmp.first>min_length) continue;  

            for(int i=0;i<4;i++)
            {
                string str_plus = tmp.second;
                string str_subs = tmp.second;
                str_plus[i]+=1;
                str_subs[i]-=1;
                if (str_plus[i] == flag_1) {
                    str_plus[i] = '0';
                }
                if(str_subs[i]==flag_2)
                {
                    str_subs[i] = '9';
                }
                if(!dead.count(str_plus) && !visited.count(str_plus))
                {
                    que.push({tmp.first+1,str_plus});
                    visited.insert(str_plus);
                }
                if(!dead.count(str_subs) && !visited.count(str_subs))
                {
                    que.push({tmp.first+1,str_subs});
                    visited.insert(str_subs);
                }
                
            }
        }
    }
};