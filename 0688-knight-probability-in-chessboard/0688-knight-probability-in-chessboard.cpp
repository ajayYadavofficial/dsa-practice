class Solution {
public:
    
    double dp[26][26][101];
    
    double solve( int row, int col, int n, int k ){
        
        
        
        if(k == 0) return 1;
        
        if(dp[row][col][k] != 0) return dp[row][col][k];
        
        int drow[] = {-1,-2,-2,-1,+1,+2,+2,+1};
        int dcol[] = {-2,-1,+1,+2,+2,+1,-1,-2};
        double res = 0;
        for(int i=0; i<8;i++){
            
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if( nrow < n && ncol < n && nrow >=0 && ncol >=0 )
                res += (0.125)*solve(nrow,ncol,n,k-1);
            
        }
        
        return dp[row][col][k] = res;
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        return solve( row, column, n, k );
    }
};