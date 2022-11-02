class Solution {
    int n;
    void dfs(int i, vector<vector<int>>& isConnected, vector<int> &vis){
        vis[i] = 1;
        
        for(int j = 0; j<n; j++){
            if(isConnected[i][j] == 1 && vis[j] == 0)
                dfs(j, isConnected, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                dfs(i, isConnected, vis);
                ans++;
            }
        }
        
        return ans;
    }
};