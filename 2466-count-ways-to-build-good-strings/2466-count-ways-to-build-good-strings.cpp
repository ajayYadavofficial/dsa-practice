// class Solution {
// public:
//     int mod = 1e9+7;
    
//     int solve(int zero, int one, int len, int currLen,vector<int> &dp){
//         if(currLen == len) return 1;
//         if(currLen > len) return 0;
//         if(dp[currLen] != -1) return dp[currLen];
        
//         int takeZero = solve(zero,one,len, currLen + zero,dp) % mod;
            
//         int takeOne = solve(zero,one,len,currLen + one,dp) % mod;
        
//         return dp[currLen] = (takeZero + takeOne) % mod;
        
//     }
    
//     int countGoodStrings(int low, int high, int zero, int one) {
     
//         int ans = 0;
//         vector<int> dp (high +1, -1);
//         for(int len = low; len <= high; len++){
//             ans = (ans + solve(zero, one, len,0,dp) ) % mod;
//         }
//         return ans;
//     }
// };


class Solution {
    int mod=1e9+7;
    int solve(int target,int one ,int zero,vector<int>&dp){
        // good string 
        if(target==0)return 1;
        // not a goood string 
        if(target<0)return 0;
        if(dp[target]!=-1)return dp[target];
        long long sum;
        sum=solve(target-one,one,zero,dp)+solve(target-zero,one,zero,dp);
        return dp[target]=sum%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int>dp(high+1,-1);
        for(int i=low;i<=high;i++){
            ans=((ans%mod)+solve(i,one,zero,dp))%mod;
        }
        return ans;
    }
};