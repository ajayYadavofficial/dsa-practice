// class Solution {
// public:
//     int min_effort = 1e9;
//     void dfs(int row, int col,vector<vector<int>>& heights, int diff, vector<vector<bool>>& visited){
        
//         if( row == 0 && col == 0){
//             min_effort = min(min_effort,diff);
//             return;
//         }
//         visited[row][col] = true;
//         int drow[] = {-1, 0, +1, 0};
//         int dcol[] = {0, +1, 0, -1};
//         for(int i=0;i<4;i++){
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];
            
//             if(nrow >=0 && ncol >= 0 && nrow <heights.size() && ncol < heights[0].size() && !visited[nrow][ncol]){
//                 // visited[nrow][ncol] = true;
//                 int change = abs(heights[row][col]-heights[nrow][ncol]);
//                 diff = max(diff,change);
//                 dfs(nrow,ncol,heights,diff,visited);
//             }
            
//         }
//     }
    
//     int minimumEffortPath(vector<vector<int>>& heights) {
        
//     }
// };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int , pair<int  ,int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist( m , vector<int> ( n , 1e9));
        dist[0][0] =  0;
        pq.push({0 , {0  , 0}});
        int dx[] = {-1, 0 , 1, 0};
        int dy[] = {0 , 1 , 0 , -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == m-1 && col == n-1){ 
                return diff;
            }
            for(int i =0;i<4;++i){
                int newr = row +dx[i];
                int newc = col + dy[i];
                if(newr >=0 && newc >= 0 && newr< m && newc<n ){
                    int newef = max(diff , abs(heights[row][col] -heights[newr][newc]));
                    if(newef < dist[newr][newc]){
                        dist[newr][newc] = newef;
                        pq.push({newef ,{newr , newc} });
                    }
                }
            }
        }
        return 0;
    }
};