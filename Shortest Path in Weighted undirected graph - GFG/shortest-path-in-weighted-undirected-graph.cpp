//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
                
        vector<vector<int>> adj[n+1];
        
        for(int i=0; i<m;i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int wt = edges[i][2];
            
            adj[node1].push_back({node2,wt});
            adj[node2].push_back({node1,wt});
            
        }
        
        
        vector<int> parent (n+1);
        parent[0] = -1;
        
        for(int i=1;i<parent.size();i++){
            parent[i] = i;
        }
        
        vector<int> dist(n+1,1e9);
        set<pair<int,int>> st;
        // distance , node
        dist[1] = 0;
        st.insert({0,1});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it : adj[node]){
                int edgWt = it[1];
                int adjNode = it[0];
                
                if(dis + edgWt < dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    
                    dist[adjNode] = dis+edgWt;
                    st.insert({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
                
            }
            
        }
        
        
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
            
        }
        
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        

    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends