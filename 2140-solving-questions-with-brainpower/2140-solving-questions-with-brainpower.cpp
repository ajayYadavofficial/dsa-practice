#define ll long long
class Solution {
public:
    
    ll solve(int ind,vector<vector<int>>& questions, vector<ll> &dp){
        int n = questions.size();
        if(ind >= n )return 0;
        if(dp[ind] != -1) return dp[ind];
        ll pick = -1e8, notPick = -1e8;
        pick = questions[ind][0] + solve(ind + questions[ind][1]+1, questions, dp);
        notPick = solve(ind+1, questions,dp);
        return dp[ind] = max(pick,notPick);
        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp (n+1,-1);
        return solve(0, questions, dp);
    }
};