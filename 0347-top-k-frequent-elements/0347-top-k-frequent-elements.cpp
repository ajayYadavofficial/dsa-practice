class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto it: nums){
            m[it]++;
        }
        vector<pair<int, int>> val(m.begin(), m.end());
        vector<int> v;
        sort(val.begin(), val.end(), [](auto &x, auto &y){return x.second > y.second;});
        auto it = val;
        for(int i=0; i<k; i++){
            v.push_back(val[i].first);
            
        }
        return v;
    }
};