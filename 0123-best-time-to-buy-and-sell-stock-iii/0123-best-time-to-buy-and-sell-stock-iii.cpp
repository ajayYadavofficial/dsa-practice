class Solution {
public:
    
    int f(int ind, int canBuy, int cap, vector<int>& prices,vector<vector<vector<int>>> &dp  ){
        
        if(ind == prices.size()){
            return 0;
        }
        if(cap == 0) return 0;
        
         if(dp[ind][canBuy][cap] != -1) return dp[ind][canBuy][cap];
//         can Buy
        int profit = 0;
        if(canBuy){          // if buying then can't buy on next day
            profit = max((-prices[ind] + f(ind +1, 0, cap, prices,dp)), (0 + f(ind+1, 1,cap,prices,dp )));
        }
//         sell if can't buy
        else{
                           // if selling then next I can buy
            profit = max((prices[ind] + f(ind+1,1,cap-1, prices,dp )),(0+f(ind+1, 0,cap, prices,dp)) );
        }
        
        return dp[ind][canBuy][cap] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(2,  vector<int>(3,-1)));
        
        return f(0,1,2,prices,dp);
    }
};