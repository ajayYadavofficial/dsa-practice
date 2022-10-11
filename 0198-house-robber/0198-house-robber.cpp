class Solution {
public:
    
    int f(int ind,vector<int>& nums,vector<int> &dp){
        if(ind >= nums.size()) return 0;
        
        if(dp[ind] != -1) return dp[ind];
//         not pick
        int notPick = 0 + f(ind+1, nums,dp);
        
//         pick
        
        
        int pick = nums[ind] + f(ind+2,nums,dp);
        
        return dp[ind] = max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size()+1, -1);
        return f(0, nums, dp);
        
    }
};