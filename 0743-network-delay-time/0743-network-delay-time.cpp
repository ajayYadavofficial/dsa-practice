class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // BELLMAN FORD ALGO
        vector<int> dist (n+1,1e8);
        dist[k] = 0;
        for( int i=0; i<n-1; i++){
            for( auto it : times){
                int u = it[0];
                int v = it[1];
                int wt= it[2];
                if( dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        int maxi = -1e9;
        for( int i = 1; i<dist.size(); i++){
            maxi = max(maxi, dist[i]);
        }
        if(maxi != 1e8)return maxi;
        return -1;
    }
};