class Solution {
public:
    
     int f(int ind, int canBuy,int fee, vector<int>& prices, vector<vector<int>> &dp  ){
        
        if(ind == prices.size()){
            return 0;
        }
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
//         can Buy
        int profit = 0;
        if(canBuy){          // if buying then can't buy on next day
            profit = max((-prices[ind] + f(ind +1, 0,fee, prices,dp)), (0 + f(ind+1, 1,fee,prices,dp )));
        }
//         sell if can't buy
        else{
                           // if selling then next I can buy
            profit = max((prices[ind]-fee+ f(ind+1,1,fee, prices,dp )),(0+f(ind+1, 0,fee, prices,dp)) );
        }
        
        return dp[ind][canBuy]  = profit;
        
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,-1));
        
        return f(0,1,fee,prices,dp);
    }
};