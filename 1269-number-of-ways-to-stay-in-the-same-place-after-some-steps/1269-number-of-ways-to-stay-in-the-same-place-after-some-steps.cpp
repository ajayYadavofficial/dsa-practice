
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int numWays(int steps, int arrLen) {
//         int mod = 1000000007;
//         int maxPosition = min(steps / 2, arrLen - 1);
//         vector<vector<int>> memo(steps + 1, vector<int>(maxPosition + 1, -1));
//         return waysToReturn(0, steps, maxPosition, memo, mod);
//     }
    
//     int waysToReturn(int position, int steps, int maxPosition, vector<vector<int>>& memo, int mod) {
//         if (position < 0 || position > maxPosition || position > steps / 2) {
//             return 0;
//         }
//         if (steps == 0) {
//             return (position == 0) ? 1 : 0;
//         }
//         if (memo[steps][position] != -1) {
//             return memo[steps][position];
//         }
        
//         int ways = 0;
//         ways = (ways + waysToReturn(position, steps - 1, maxPosition, memo, mod)) % mod;
//         ways = (ways + waysToReturn(position - 1, steps - 1, maxPosition, memo, mod)) % mod;
//         ways = (ways + waysToReturn(position + 1, steps - 1, maxPosition, memo, mod)) % mod;
        
//         memo[steps][position] = ways;
//         return ways;
//     }
// };



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
