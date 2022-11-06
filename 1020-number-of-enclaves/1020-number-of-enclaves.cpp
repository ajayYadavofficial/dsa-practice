class Solution {
    
    private:
    void dfs(int i, int j,int n, int m,vector<vector<int>>& vis, vector<vector<int>>& board ){
        if( i < 0 || j<0 || i >= n || j >= m || board[i][j] == 0 || vis[i][j] == 1){
            return;
        }
        vis[i][j] = 1;
        //call dfs for all paths 
        
        // upward 
        dfs(i-1,j,n,m,vis,board);
        
        //down
        dfs(i+1,j,n,m,vis,board);
        
        // left
        dfs(i,j-1,n,m,vis,board);
        
        // right
        dfs(i,j+1,n,m,vis,board);
        
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        
        for(int i=0 ;i <n;i++){
            for(int j = 0; j<m;j++){
                if( i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(board[i][j] == 1 && !vis[i][j]){
                        dfs(i,j,n,m,vis,board);
                    }
                }
            }
        }
        
        int count = 0;
        for(int i=0 ;i <n;i++){
            for(int j = 0; j<m;j++){
                if(board[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        
        return count;
    }
};