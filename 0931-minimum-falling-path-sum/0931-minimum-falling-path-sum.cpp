class Solution {
public:
    
    int f(int i, int j,vector<vector<int>>& matrix,int &n, vector<vector<int>> &dp ){
        
        if( i == n-1) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int down    = matrix[i][j] + f(i+1, j , matrix,n,dp);
            
        int diagLeft = 1e9, diagRight = 1e9;
            
         if( j -1 >= 0 )diagLeft = matrix[i][j] +f(i+1, j-1 , matrix,n,dp);
            
         if(j+1 <= n-1)diagRight = matrix[i][j] +f(i+1, j+1 , matrix,n,dp);
        
        return dp[i][j] = min({down,diagLeft, diagRight});
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int ans = 1e9;
        
        int n= matrix.size();
        vector<vector<int>> dp( n , (vector<int>(n,-1)));
        for(int i=0; i<n;i++){
            ans = min(ans,f(0,i,matrix,n,dp));
        }
        return ans;
    }
};