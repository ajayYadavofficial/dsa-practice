class DSU {
    vector<int>parent, rank;
    public:
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }
    
        int findUPar(int n){
            return parent[n] =  parent[n] == n ? n : findUPar(parent[n]);
        }
        // int findUPar(int node) {
        //     if(node == parent[node])
        //         return node; 
        //     return parent[node] = findUPar(parent[node]); 
        // }
        bool unionByRank(int u, int v) {
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return false; 
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v; 
            }
            else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u; 
            }
            else {
                parent[ulp_v] = ulp_u; 
                rank[ulp_u]++; 
            }
            return true;
        }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int rmv_edge = 0;
        DSU alice_dsu(n);
        DSU bob_dsu(n);
        int alice_edges = 0, bob_edges = 0;
        
        
        // firt of all add those paths which are common for both 
        for(auto it : edges){
            if(it[0] == 3){
                if(alice_dsu.unionByRank(it[1],it[2])){
                    bob_dsu.unionByRank(it[1],it[2]);
                    alice_edges++;
                    bob_edges++;
                }else{
                    rmv_edge++;
                }
            }
        }
        
        for(auto it : edges){
            if(it[0] != 3){
                
                // for bob only
                if(it[0] == 2){
                    
                    if(bob_dsu.unionByRank(it[1],it[2])){
                        bob_edges++;
                    }else{
                        rmv_edge++;
                    }
                    
                }
                
                // for alice
                else if(it[0] == 1){
                    
                    if(alice_dsu.unionByRank(it[1],it[2])){
                        alice_edges++;
                    }else{
                        rmv_edge++;
                    }
                    
                }
                
            }
        }
        
        return (alice_edges == n-1 && bob_edges == n-1) ? rmv_edge : -1;
        
    }
};