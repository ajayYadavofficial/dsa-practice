class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>> adj[n+1];
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int dist = it[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        
        vector<bool> visited(n+1,0);
        int ans = INT_MAX;
        visited[1] = true;
        queue<int> q; // <node>
        q.push(1);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                // cout<<*it<<endl;
                int adjNode = it[0];
                int dist = it[1];
                ans = min(ans,dist);
                if(!visited[adjNode]){
                    visited[adjNode] = true;
                    q.push(adjNode);
                }
            }
            
        }
        
//         for(auto it : roads){
//             int u = it[0];
//             int v = it[1];
//             int dist = it[2];
            
//             if(visited[u] && visited[v]){
//                 ans = min(ans,dist);
//             }
            
//         }
        return ans;
        
    }
};