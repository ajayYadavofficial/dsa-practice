class Solution {
public:
    
    int f(int ind, int canBuy, vector<int>& prices, vector<vector<int>> &dp  ){
        
        if(ind == prices.size()){
            return 0;
        }
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
//         can Buy
        int profit = 0;
        if(canBuy){          // if buying then can't buy on next day
            profit = max((-prices[ind] + f(ind +1, 0, prices,dp)), (0 + f(ind+1, 1,prices,dp )));
        }
//         sell if can't buy
        else{
                           // if selling then next I can buy
            profit = max((prices[ind] + f(ind+1,1, prices,dp )),(0+f(ind+1, 0, prices,dp)) );
        }
        
        return dp[ind][canBuy]  = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,0));
        vector<int> next (2,0), curr (2,0);
        
//         Base case
        next[0] = next[1] = 0; // not necessary 
        
        for(int ind = n-1; ind>=0; --ind){
            for(int canBuy = 1; canBuy >=0; --canBuy){
                
                int profit = 0;
                    if(canBuy){          // if buying then can't buy on next day
                        profit = max((-prices[ind] + next[0]), (0 + next[1]));
                    }
            //         sell if can't buy
                    else{
                                       // if selling then next I can buy
                        profit = max((prices[ind] + next[1]),(0+next[0]) );
                    }

                   curr[canBuy]  = profit;
                
            }
            next = curr;
        }
        
        return curr[1];
    }
};