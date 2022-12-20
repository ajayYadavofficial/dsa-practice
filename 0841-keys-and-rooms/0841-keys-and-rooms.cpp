class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        
        while(!q.empty()){
            int node = q.front();
            vis[node] = true;
            q.pop();
            
            for(int it : rooms[node]){
                int adjNode = it;
                if(!vis[adjNode]){
                    q.push(adjNode);
                }
                
            }   
        }
        for(int i=0; i<n; i++)
            if(!vis[i]) return false;
           
        return true;
        
    }
};