class Solution {
public:
    
    int f(int ind, int prev_ind,vector<int>& nums, vector<vector<int>> &dp){
        
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prev_ind + 1] != -1){
            return dp[ind][prev_ind + 1];
        }
        
//         notTake
        int notTake = 0 + f(ind+1, prev_ind,nums,dp);
        
//         Take
        int take = -1e5;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            take = 1 + f(ind +1, ind, nums,dp); 
        }
        return dp[ind][prev_ind + 1] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<vector<int>> dp (n+1, vector<int>(n+1, 0));
//         for(int ind = n-1; ind >=0; ind--){
//             for(int prev_ind = ind-1; prev_ind >= -1; prev_ind --){
// //                 notTake
//                 int notTake = 0 + dp[ind+1][prev_ind+1];    // send prev_ind with +1 becoz of right shift that we have considered
        
// //         Take
//                 int take = -1e5;
//                 if(prev_ind  == -1 || nums[ind] > nums[prev_ind]){
//                     take = 1 + dp[ind +1][ind+1]; 
//                 }
//                dp[ind][prev_ind + 1] = max(take,notTake);
//                     }
//                 }
        
//         return dp[0][-1+1];
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1; i<nums.size();i++){
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;}
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }    
            
      return len;      
    }
};