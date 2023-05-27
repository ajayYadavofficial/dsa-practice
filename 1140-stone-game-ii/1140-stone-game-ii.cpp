class Solution {
public:
    int dp [2][101][101];
    int solve(int ind, int isAlice, int M, vector<int>& piles){
        int n = piles.size();
        if(ind >= n) return 0;
        
        if(dp[isAlice][ind][M] != -1) return dp[isAlice][ind][M];
        
        int result = (isAlice) ? -1 : INT_MAX;
        int stones = 0;
        for(int x = 1; x<= min(2*M,n-ind); x++){
            stones += piles[x+ind-1];
            if(isAlice){
                result = max(result, stones + solve(ind+x, 0, max(x,M), piles) );
            }
            else{
                result = min(result,solve(ind+x, 1, max(x,M), piles) );
            }
        }
        return dp[isAlice][ind][M] =  result;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(0,1,1,piles);
    }
};