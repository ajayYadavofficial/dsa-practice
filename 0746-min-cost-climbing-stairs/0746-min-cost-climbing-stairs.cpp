class Solution {
public:
    
    
   int minCostClimbingStairs(vector<int>& heights) {
        int n=heights.size();
        
       vector<int> dp(n+1,-1);  
        dp[0]=heights[0];
        dp[1]=heights[1];
        for(int i=2;i<n;i++)
             dp[i]=min(dp[i-1],dp[i-2])+heights[i];
         return min(dp[n-1],dp[n-2]);
        
    }
};