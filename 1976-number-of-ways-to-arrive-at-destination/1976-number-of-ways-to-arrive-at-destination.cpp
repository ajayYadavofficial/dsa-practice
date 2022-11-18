#define ll long long
class Solution {
public:
int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<ll,ll>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> ways(n,0),dist(n,LONG_MAX);
    pq.push({0,0});
    dist[0]=0;
    ways[0]=1;
    int mod=1e9+7;
    
    while(!pq.empty()){
        ll dis=pq.top().first;
        ll node=pq.top().second;
        pq.pop();
        
        for(auto it:adj[node]){
            ll adjNode=it.first;
            ll edgeW=it.second;
            
            if(edgeW+dis< dist[adjNode]){
                dist[adjNode]=edgeW+dis;
                pq.push({edgeW+dis,adjNode});
                ways[adjNode]=ways[node];
            }
            else if(edgeW+dis==dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
            
        }
    }
    return ways[n-1]%mod;
}
};