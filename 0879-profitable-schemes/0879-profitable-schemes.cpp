// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int solve( int ind, int max_people, int group_size, int profit_so_far, int minProfit, vector<int>& group, vector<int>& profit){
        
//         if( ind < 0){
//             if( profit_so_far >= minProfit) return 1;
//             return 0;
//         }
        
//         int pick = 0;
//         if(group_size + group[ind] <= max_people){
            
//             pick = solve(ind -1, max_people, group_size + group[ind], profit_so_far + profit[ind], minProfit, 
//                         group, profit);
//         }
//         // not pick
//         int notPick = solve( ind -1,max_people ,group_size,profit_so_far, minProfit, 
//                         group, profit);
        
//         return (pick % mod + notPick % mod) % mod;
        
//     }
    
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         int m = group.size();
        
//         // 3d dp
//         vector<vector<vector<int>>> dp (m, vector<vector<int>>(n, vector<int>(minProfit +1 , -1)  ));
        
//         return solve( m-1, n, 0, 0, minProfit,group, profit );
//     }
// };

class Solution {
public:
   int dp[102][102][102];
    int mod=1e9+7;
    int solve(int k,int i, int j,int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        if(k==profit.size())
        {
            if(j>=minProfit and n>=i) return 1;
            return 0;
        }
        else if(n<i) return 0;
     
        if(dp[k][i][j]!=-1) return  dp[k][i][j];
        int include=0,notInclude=0;
        notInclude= solve(k+1,i,j,n,minProfit,group,profit);
        include=solve(k+1,i+group[k],min(j+profit[k],minProfit),n,minProfit,group,profit);
        return  dp[k][i][j] = (include  % mod + notInclude  % mod )%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minProfit,group,profit);
        
    }
};