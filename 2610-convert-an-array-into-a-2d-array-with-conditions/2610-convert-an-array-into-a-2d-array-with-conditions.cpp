class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> res;
    unordered_map<int, int> cnt;
    for (auto n : nums)
        ++cnt[n];
    while(!cnt.empty()) {
        res.push_back({});
        for (auto it = begin(cnt); it != end(cnt); ) {
            res.back().push_back(it->first);
            if (--it->second == 0)
                cnt.erase(it++);
            else
                ++it;
        }
    }
    return res;
}
};