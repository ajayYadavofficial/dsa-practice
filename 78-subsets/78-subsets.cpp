class Solution {
public:
   void dfs(int i, vector<int>& sub, vector<int>& nums, vector<vector<int>> &res) {
        
        if(i == nums.size()) {
            res.push_back(sub);
            return;
        }
        
        // Don't take this element
        dfs(i + 1, sub, nums, res);
        
        // Take this element
        sub.push_back(nums[i]);
        dfs(i + 1, sub, nums, res);
        sub.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        dfs(0, sub, nums, res);
        return res;
    }
};