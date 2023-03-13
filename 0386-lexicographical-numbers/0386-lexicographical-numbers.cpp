class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1, i=0;
        while(i++ < n) {
            ans.emplace_back(cur);
            if (cur * 10 <= n) cur *= 10;
            else {
                if (cur == n) cur /= 10;
                cur += 1;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return ans;
    }
};