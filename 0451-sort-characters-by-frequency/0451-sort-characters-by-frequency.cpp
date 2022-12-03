class Solution {
public:
    string frequencySort(string s) {
         map<char,int> mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        string ans = "";
        while(!pq.empty())
        {
            int freq = pq.top().first;             
            char ch = pq.top().second;             
            pq.pop();                              
            
            for(int i=0;i<freq;i++)
            {
                ans += ch;
            }
        }
        
        return ans;
        
    }
};