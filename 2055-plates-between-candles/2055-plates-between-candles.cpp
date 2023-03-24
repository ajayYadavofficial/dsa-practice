class Solution {
public:
   vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> psum(s.size() + 1), next(s.size() + 1, INT_MAX), prev(s.size() + 1), res;
    for (int i = 0; i < s.size(); ++i) {
        psum[i + 1] = psum[i] + (s[i] == '|');
        prev[i + 1] = s[i] == '|' ? i : prev[i];
    }
    for (int i = s.size() - 1; i >= 0; --i)
        next[i] = s[i] == '|' ? i : next[i + 1];
    for (auto &q : queries) {
        int l = next[q[0]], r = prev[q[1] + 1];
        res.push_back(l < r ? r - l - (psum[r] - psum[l]) : 0);
    }
    return res;
}  
};