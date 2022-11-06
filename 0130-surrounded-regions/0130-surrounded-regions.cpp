class Solution {
private:
    void dfs(int i, int j,int n, int m,vector<vector<int>>& vis, vector<vector<char>>& board ){
        if( i < 0 || j<0 || i >= n || j >= m || board[i][j] == 'X' || vis[i][j] == 1){
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
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        
        for(int i=0 ;i <n;i++){
            for(int j = 0; j<m;j++){
                if( i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(board[i][j] == 'O' && !vis[i][j]){
                        dfs(i,j,n,m,vis,board);
                    }
                }
            }
        }
        
        
        for(int i=0 ;i <n;i++){
            for(int j = 0; j<m;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};