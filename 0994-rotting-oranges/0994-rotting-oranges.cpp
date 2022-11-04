class Solution {    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> Q;
//         Q look like {{r,c},t}
        for(int i=0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    Q.push({{i,j},0});
                }
            }
        }
        
        int ansTime = 0;
        
        while(!Q.empty()){
            int drow[] = {-1,0,+1,0};
            int dcol[] = {0,+1,0,-1};
            int r = Q.front().first.first;
            int c = Q.front().first.second;
            int t = Q.front().second;
            ansTime = max(ansTime,t);
            Q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] 
                   && grid[nrow][ncol] == 1 ){
                    Q.push({ {nrow, ncol},t+1  });
                    vis[nrow][ncol] = 2;
                }
                
            }  
        }
        for(int i=0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        
        return ansTime;
        
    }
};