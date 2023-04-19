//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        // distance, <row, col>
        
        q.push({0, {source.first, source.second}});
        
        vector<vector<int>> dist (n, vector<int>(m , 1e9));
        
        dist[source.first][source.second] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curr_dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            int drow[] = {-1,0,+1,0};
            int dcol[] = {0,+1,0,-1};
            for( int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && ncol >=0 && nrow< n && ncol < m && 
                grid[nrow][ncol] == 1 && curr_dist + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = curr_dist + 1;
                    // if( nrow == destination.first && ncol == destination.second){
                    //     return dist[nrow][ncol];
                    // }
                    q.push({ dist[nrow][ncol] , {nrow, ncol}});
                }
                
            }
        }
        if( dist[destination.first][destination.second] == 1e9) return -1;
        return dist[destination.first][destination.second];
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends