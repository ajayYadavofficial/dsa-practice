#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>> Q;
        
        // stored the starting pts in queue
        for(int i =0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    Q.push({{i,j},0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        
        
        while(!Q.empty()){
            
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int d = Q.front().second;
            Q.pop();
            dist[row][col] = d;
            vis[row][col] = 1;
            
            int drow[] = {-1,0,+1,0};
            int dcol[] = {0,+1,0,-1};
            
            for(int i=0; i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    Q.push({{nrow,ncol},d+1});
                }
                
            }
            
        }
        
        return dist;
    }
};

