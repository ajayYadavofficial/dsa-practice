// class Solution {
// public:
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>> ans;
        
//         queue<int> q;
//         q.push(0);
//         vector<int> path;
        
//         while(!q.empty()){
//             int node = q.front();
//             path.push_back(node);
//             q.pop();
            
//             for(auto it : graph[node]){
//                 if(it == graph.size()){
//                     path.push(it);
//                     ans.push(path);
//                 }
//             }
            
//         }
        
//     }
// };
class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& v, int start) {
        for (int i = 0; i < graph[start].size(); i++) {
            v.push_back(graph[start][i]);
            if (graph[start][i] == graph.size() - 1) ans.push_back(v);
            dfs(graph, ans, v, graph[start][i]);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v; v.push_back(0);
        vector<vector<int>> ans;
        dfs(graph, ans, v, 0);
        return ans;
    }
};