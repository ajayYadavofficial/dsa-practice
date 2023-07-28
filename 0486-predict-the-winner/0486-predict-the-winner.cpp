class Solution {
public:
    
    int dp[21][21];
    
    int solve(int left, int right, vector<int>& nums ){
        
        if(left > right){
            return 0;
        }
        
        if(dp[left][right] != -1) return dp[left][right];
                                        // min( nexttakeleft, nexttakeRight );
        int take_left = nums[left] + min( solve(left+2,right, nums ) , solve( left+1, right-1, nums ));   
        
        int take_right = nums[right] + min(solve(left+1, right-1, nums) , solve(left, right-2, nums));
        
        return dp[left][right] = max(take_left , take_right);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        int tot_sum = 0;
        
        for(auto it : nums) tot_sum += it;
        
        int Asum =  solve(0,nums.size()-1, nums);
        
        int Bsum = tot_sum - Asum;
        
        return Asum >= Bsum;
        
    }
};