class Solution {
public:
    int mod = 1e9+7;
    
    int solve(int zero, int one, int len,vector<int> &dp){
        if(len == 0) return 1;
        if(len < 0 ) return 0;
        if(dp[len] != -1) return dp[len];
        
        int takeZero = solve(zero,one,len- zero,dp) % mod;
            
        int takeOne = solve(zero,one,len-one,dp) % mod;
        
        return dp[len] = (takeZero + takeOne) % mod;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
     
        int ans = 0;
        vector<int> dp (high +1, -1);
        for(int len = low; len <= high; len++){
            ans = (ans + solve(zero, one, len,dp) ) % mod;
        }
        return ans;
    }
};