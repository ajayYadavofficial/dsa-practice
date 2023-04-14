class Solution {
public:
bool dfs(int v,vector<vector<int>>& graph, vector<int> &vis){
       vis[v]=1;
       for(auto it:graph[v]){
           if(vis[it]==0){
               if(dfs(it,graph,vis)) return 1;
           }
           else if(vis[it]==vis[v]) return 1;
       }

       vis[v]=3;

       return 0;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            vector<int> vis(graph.size(),0);
                if(!dfs(i,graph,vis)){
                    //if not cycle;
                    ans.push_back(i);
                }
            
        }

        return ans;
    }
};