class Solution {
public:
   int findTargetSumWays(vector<int>& nums, int target) {
int sum = 0;
 int raw = nums.size();  
 sum= accumulate(nums.begin(),nums.end(),sum);
if((sum + target)%2 != 0) return 0;
int col = (sum+target)/2;
if(col < 0) return 0;
vector<vector<int>> dp(raw+1,vector<int>(col+1,0));

for(int i = 0; i <raw+1; i++){
    dp[i][0]=1;
    
}
for(int i = 1; i<raw+1; i++){
    for(int j = 0; j<col+1; j++){
        if(nums[i-1] <= j) dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
        else dp[i][j] = dp[i-1][j];
    }
}

return dp[raw][col];
}
};