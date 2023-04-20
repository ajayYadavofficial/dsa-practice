//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        
        for(int i=0;i<flights.size(); i++){
            int start = flights[i][0];
            int stop = flights[i][1];
            int dist = flights[i][2];
            
            adj[start].push_back({stop,dist});
            
        }
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int , pair<int,int> >> Q;
        //queue of pair of {stops, {node, distance}}
        //allowed stops = k+1;
        Q.push({0, {src,0}} );
        
        
        while(!Q.empty()){
            
            int node = Q.front().second.first; 
            int stops= Q.front().first;
            int cost = Q.front().second.second;
            Q.pop();
            
            if(stops > k) continue;
            
            for(auto it : adj[node]){
                
                int adjNode = it.first;
                int edWt = it.second;
                
                if(cost + edWt < dist[adjNode]){
                    dist[adjNode] = cost + edWt;
                    Q.push({stops+1, {adjNode, dist[adjNode]}});
                    
                } 
                
            }
            
        }
                
        if(dist[dst] == 1e9) return -1;
                
        return dist[dst];
        
    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends