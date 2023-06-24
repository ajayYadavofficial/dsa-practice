     const int MIN = -1e4, offset = 5000;
class Solution {
    int ans, n;
vector<int> rods;
int dp[21][2 * offset + 1];
public:
    
//     int solve(int ind, int S1, int S2, vector<int>& rods ,vector<vector<int>> &dp ){
        
//         if(ind >= rods.size()) return (S1 == S2) ? S1 : 0;
        
//         // not Take
//         if(dp[ind][5000 + S1-S2] != -1) return dp[ind][5000 + S1-S2];
//         int notTake = solve(ind+1, S1, S2, rods,dp);
        
//         int Take = max(solve(ind+1, S1 + rods[ind], S2, rods,dp) , solve(ind +1, S1, S2 + rods[ind], rods,dp) );
        
//         return dp[ind][5000 + S1-S2] = max(notTake, Take);
    
//     }
    
//     int tallestBillboard(vector<int>& rods) {
        
//         int n = rods.size();
//         vector<vector<int>> dp ( 21 , vector<int>( 10005, -1 ) );
//         return solve(0,0,0,rods, dp);
//     }
    

int tallestBillboard(vector<int>& rods) {

this->rods = rods;
n = rods.size();
memset(dp , -1 , sizeof(dp));
int ans = solve(0, 0);
if (ans < 0)return 0;
else return ans;
}
int solve(int i, int diff) {
if (i == n) {
if (diff == 0)return 0;
return INT_MIN;
}
int &ans = dp[i][diff + offset];
if (ans != -1)return ans;
int opt1 = solve(i + 1 , diff);
int opt2 = rods[i] + solve(i + 1 , diff +
rods[i]);
int opt3 = solve(i + 1 , diff - rods[i]);
return ans = max({opt1, opt2, opt3});
}
};