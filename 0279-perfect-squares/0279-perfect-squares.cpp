class Solution {
public:
    int numSquares(int n) {
        if( n == 0 || n == 1) return n;
        vector<int> dp( n+1, 0);
        dp[0] = 0; dp[1] = 1;
        
        for(int i =2; i<n+1; i++){
            int mini = 1e9;
            for(int j = 1; j*j<=i; j++ ){
                int rem = i - j*j;
                if(dp[rem] < mini){
                    mini = dp[rem];
                }
            }
            dp[i] = mini + 1;
        }
        return dp[n];
        
    }
};