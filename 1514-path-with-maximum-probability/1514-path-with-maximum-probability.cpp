// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
//         vector<pair<int,double>> adj[n];
//         // <node , succProb>
//         for(int i=0; i<edges.size();i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             adj[u].push_back({v,succProb[i]});
//             adj[v].push_back({u ,succProb[i] });
//         }
        
//         /* for printing the adj Graph*/
//         // for(auto it : adj){
//         //     for(auto it1 : it){
//         //         cout<<it1.first<<" "<<it1.second<<endl;
//         //     }
//         //     cout<<endl;
//         // }
        
//         vector<bool> vis(n,0);
//         queue<pair<int, double>> q;
//         // node, prob_so_far
//         q.push({start , 1.0});
//         vis[start] = true;
        
//         double ans = 0.0;
        
//         while(!q.empty()){
//             int node = q.front().first;
//             double prob_so_far = q.front().second;
//             vis[node] = true;
//             q.pop();
            
//             for(auto it : adj[node]){
                
//                 int ajdNode = it.first;
//                 double prob = it.second;
//                 if(!vis[ajdNode]){
                    
//                     // cout<<ajdNode<<" "<<prob*prob_so_far<<endl;
//                     if(ajdNode == end){
//                         ans = max(ans, prob*prob_so_far);
//                         cout<<ans<<" = ans"<<endl;
//                     }
//                     q.push({ajdNode, prob*prob_so_far});
                    
//                 }
                
//             }
            
//         }
        
        
        
        
//         return ans;
//     }
// };


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        // creating adjacency List
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

      
       
 
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {

            int curr = q.front();
            q.pop();
            
            for (auto it : adj[curr]) {

                int nextNode = it.first;
                double prob = it.second;

                double newProb = dist[curr] * prob;
                
                if (newProb > dist[nextNode]) {
                    dist[nextNode] = newProb;
                    q.push(nextNode);
                }
            }
        }
        
        return dist[end];
    }
};