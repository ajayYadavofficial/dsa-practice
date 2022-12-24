class Solution {
private:
    const long long mod = 1e9+7;
public:
    int numTilings(int n) {
        vector<long long> dp(1000, 0);
        //If n<=3
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(n<=3){
            return dp[n];
        }
        //If n>3
        for(int i=4;i<=n;i++){
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]%=mod;
        }
        return dp[n]%mod;
    }
};
