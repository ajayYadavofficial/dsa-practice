class Solution {
public:
    int solve(int ind, vector<int>& arr, int difference, int prevInd, map<pair<int,int>,int> &dp){
        
        int n = arr.size();
        
        if(ind == n) return 0;
        
        if(dp.find({ind, prevInd}) != dp.end() ) return dp[{ind, prevInd}] ;
        
        int notTake = 0 + solve(ind+1, arr, difference, prevInd,dp);
        
        int take = INT_MIN;
        
        if( prevInd == -1 || ( arr[ind] -  arr[prevInd] == difference  )  ){
            take = 1 + solve( ind+1, arr, difference, ind , dp );
        }
        return dp[{ind, prevInd}] = max(take,notTake);
        
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // map<pair<int,int>,int> dp;
        int dp[50004] = {0};
        int ans = INT_MIN;
        for(int i= 0; i< arr.size(); i++){
            dp[arr[i] + 20000] = 1 + dp[arr[i] - difference + 20000];
            ans = max(ans, dp[arr[i] + 20000]);
        }
        
        return ans;
    }
};