class Solution {
public:
    
    int dp[301][5002];
    
    // ind,target
    
    int solve( int ind, int target, int n,vector<int>& coins  ){
        
        if( ind >= n){
            return target == 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = solve(ind+1,target, n, coins);
        int take = 0;
        
        if(coins[ind] <= target) take = solve(ind, target-coins[ind], n, coins);
        
        return dp[ind][target] = take + notTake;
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        memset(dp,-1, sizeof(dp));
        int n = coins.size();
        
        return solve(0,amount,n,coins);
    }
};