class Solution {
public:
    
    
    int f(int i, int j1, int j2, int r, int c,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp ){
        
//         exceed boundary
        if( j1 <0 || j2< 0|| j1>= c || j2 >= c){
            return -1e8;
        }
        
//         base case to stop at last row
        if( i == r-1){
            
            if(j1 == j2) return grid[i][j1]; /* reached at the same cell at last*/ 
            
            return grid[i][j1] + grid[i][j2]; /*not a same cell at last*/
            
        }
        
        /*now for rules checking we are going to check for all paths using the loop is for, as if ROBOT 1 goes down then ROBOT 2 has 3 choices to go so we have to consider all the choices  */
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e6;
        
        for(int dj1 = -1; dj1 <= +1; dj1 ++){
            
            for(int dj2 = -1; dj2 <= +1; dj2++){
                // if both reaches to same cell consider only on the ans
                if(j1 == j2){
                    maxi = max(maxi,grid[i][j1] + f(i+1, j1+dj1, j2+dj2, r,c, grid, dp));
                }
                else{
                    // if both at different cell then consider both the cells for the ans
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, r,c, grid, dp) );
                }
                
            }
            
        }
        
        return dp[i][j1][j2] = maxi;
        
        
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp (r , vector<vector<int>>(c, vector<int>(c, -1)  )) ;
        return f(0,0,c-1,r,c,grid, dp );
    }
};