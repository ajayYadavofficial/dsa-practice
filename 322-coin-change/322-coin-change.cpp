class Solution {
public:
    int coinChange(vector<int>& coins, int p) {
        
        vector<int> prev(p+1, 0), curr(p+1,0);
    
    for(int T=0; T<=p; T++){
        if(T%coins[0] == 0) prev[T] = T/coins[0];
        else prev[T] = 1e9;
    }
     for(int ind =1; ind< coins.size(); ind++){
        
        for(int T = 0; T <= p; T++){
//             not Take     
            int notTake = 0 + prev[T];

        //     Take
            int take = INT_MAX;
            if(coins[ind] <= T){
                take = 1 + curr[ T - coins[ind]];
            }
            
            curr[T] =  min(take, notTake);
        }
        prev = curr;
    } 
        
        int ans = prev[p];
        if(ans == 1e9) return-1;
        return ans;
    }
};