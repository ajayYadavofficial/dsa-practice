class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n,false);
        
        queue<int> q;
         q.push(source); 
        vis[source]=true;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            if(node == destination){
                return true; 
            }
            
            for(int adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = true;
                    q.push(adjNode);
                }
            }
            
        }
        return false;
        
    }
};