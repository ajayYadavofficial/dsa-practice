//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    private:
    void dfs(int row, int col, int n, int m,vector<vector<int>> &vis,vector<pair<int,int>> &vec,vector<vector<int>>& grid, int row0, int col0 ){
        vis[row][col] = 1;
        // where row0 & col0 are base coordinates
        vec.push_back({row-row0, col-col0});
        
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        for(int i=0; i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && nrow < n && ncol >=0 && ncol <m && !vis[nrow][ncol] 
            && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,n,m,vis,vec, grid, row0, col0);
            }
            
            
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0; j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,n,m,vis,vec,grid,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends