class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>result(T.size());
            
            //递减栈
        stack<pair<int,int>> record;
        vector<pair<int,int>> record_T;
        
        
        // 初始化
        for(int i =0;i<T.size();i++)
        {
            record_T.push_back(pair<int,int>(T[i],i));
        }
        
        for(int i=0;i<record_T.size();i++)
        {
            if(record.empty())
                record.push(record_T[i]);
            else
            {
                while(!record.empty() && record.top().first<record_T[i].first){
                    result[record.top().second] = i - record.top().second;
                    record.pop();
                }
                record.push(record_T[i]);
            }
        }
        while(!record.empty())
        {
            result[record.top().second] =0;
            record.pop();
        }
        return result;
    }
};
