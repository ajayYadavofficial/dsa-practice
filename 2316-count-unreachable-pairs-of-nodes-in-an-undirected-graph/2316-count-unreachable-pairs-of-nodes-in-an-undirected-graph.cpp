// class Solution {
// public:
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         if(edges.size() == 0) return (n*(n-1))/2;
//         map<int,vector<int>> group;
        
//         vector<int> adj[n];
//         for(auto it : edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
//         // for(auto it : adj){
//         //     for(auto it1 : it){
//         //         cout<<it1<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         vector<bool> visi (n,0);
//         queue<int> q;
//         q.push(0);
//         visi[0] = true;
//         int cnt =0;
//         for(int i=0; i<n;i++){
//             // groups[cnt].push_back(0);
//             // if(visi[i] == true) continue;
//             if(!visi[i]){ 
//                 cnt++;
//                 q.push(i);
//                 visi[i] = true;
//             }
//             while(!q.empty()){
//                 int node = q.front();
//                 q.pop();
//                 group[cnt].push_back(node);
//                 for(auto it : adj[node]){
//                     int adjNode = it;
//                     if(!visi[adjNode]){
//                         q.push(adjNode);
//                         visi[adjNode] = true;
//                     }
//                 }
//             }
//         }
//         cout<<cnt<<" cnt"<<endl;
//         int ans = 0;
//         // if(group.size() == 1) return 0;
//         // for(auto it : group){
//         //     for(auto it1 : it.second){
//         //         cout<<it1<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
//         for(int i=0; i<group.size()-1;i++){
//             for(int j = i+1; j<group.size(); j++ ){
//                 int s1 = group[i].size();
//                 int s2 = group[j].size();
//                 ans += s1*s2;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    long countPairs(int n, vector<vector<int>>& edges) {
        createGraph(n, edges);
        vector<bool> visited(n, false);
        int numberOfVisitedNodes = 0;
        long numberOfUnreachablePairsOfNodes = 0;

        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                int numberOfNodesInCurrentGroup = depthFirstSearch_countConnectedNodesInCurrentGroup(node, visited);
                numberOfUnreachablePairsOfNodes += (long) numberOfNodesInCurrentGroup * numberOfVisitedNodes;
                numberOfVisitedNodes += numberOfNodesInCurrentGroup;
            }
        }
        return numberOfUnreachablePairsOfNodes;
    }

private:
    vector<int>* graph;

    int depthFirstSearch_countConnectedNodesInCurrentGroup(int node, vector<bool>& visited) {
        visited[node] = true;
        int countConnectedNodes = 1;

        for (int neighbour : graph[node]) {
            if (!visited[neighbour]) {
                countConnectedNodes += depthFirstSearch_countConnectedNodesInCurrentGroup(neighbour, visited);
            }
        }
        return countConnectedNodes;
    }

    void createGraph(int numberOfNodes, vector<vector<int>>& edges) {
        graph = new vector<int>[numberOfNodes];
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
};