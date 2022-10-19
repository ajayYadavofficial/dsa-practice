// class Solution {
// public:
//     static bool sortByVal( pair<string, int> &a,  pair<string, int> &b) 
//         { 
//                 return a.second > b.second;
//         }       
//     static bool compare(string a, string b)
//         {
//             if (a.compare(0, b.size(), b) == 0
//                 || b.compare(0, a.size(), a) == 0)
//                 return a.size() > b.size();
//             else return a < b;
//         }
    
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         int n = words.size();
//         sort(words.begin(), words.end(), compare);
//         map<string,int> m;
//         for(int i =0; i<n;i++){
//             m[words[i]] ++;
//         }
//         vector<pair<string,int>> vec(m.begin(),m.end());
//         sort(vec.begin(), vec.end(), sortByVal);
//         // for(auto it: vec){
//         //     cout<<it.first<<" "<<it.second<<endl;
//         // }
//         vector <string> ans;
//         for(int i=0;i<k;i++){
//             ans.push_back(vec[i].first);
//         }
//         return ans;
//     }
// };

struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++)
            m[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for(auto p : m)
            q.push({p.second, p.first});
        
        vector<string> ans;
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};