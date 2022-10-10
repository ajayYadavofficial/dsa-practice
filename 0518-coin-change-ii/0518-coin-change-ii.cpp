class Solution {
public:
    int change(int value, vector<int>& a) {
        
        vector<int> prev(value+1, 0), cur(value+1, 0);
        
        for(int T=0; T<=value; T++){
//         dp[0][T] = (T%a[0] == 0);
        prev[T] = (T%a[0] == 0);
    }
    
    for(int ind = 1; ind <a.size();ind++){
        for(int T = 0; T<= value; T++){
//          long notTake = dp[ind - 1][T];
            long notTake = prev[T];
    
            long take = 0;
            if(a[ind] <= T){
//              take = dp[ind][T-a[ind]];
                take = cur[T-a[ind]];
            }
//          dp[ind][T] = take + notTake;
            cur[T] = take + notTake;
        }
        //empty
        prev = cur;
    }
    
//  return dp[n-1][value];
    return prev[value];
    
        
    }
};