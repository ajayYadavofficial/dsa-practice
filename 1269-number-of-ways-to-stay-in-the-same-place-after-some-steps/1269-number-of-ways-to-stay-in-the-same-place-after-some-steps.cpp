#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9+7;
        int maxPosition = min(steps / 2, arrLen - 1);
        vector<vector<long long>> dp(steps + 1, vector<long long>(maxPosition + 1, 0));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxPosition; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if (j < maxPosition) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        
        return dp[steps][0];
    }
};
