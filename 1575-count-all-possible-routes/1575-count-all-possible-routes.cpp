class Solution {
public:
    
    int dp[101][201];
    // ind, end, fuel
    
    int mod = 1e9+7;
//     void dfs( int ind, int end, int fuel, vector<int>& locations){
        
//         if(ind >= locations.size()) return;
//         if(ind == end && fuel >= 0){ cout<<fuel<<endl;cnt++;}
        
//         for(int i=0; i<locations.size(); i++){
//             if(ind == i) continue;
            
//             int wt = abs(locations[ind] - locations[i]);
//             // check for fuel condition to go next 
//             if(wt <= fuel)dfs(i, end, fuel-wt, locations);
                
            
//         }
        
//     }
    
    long dfs( int ind, int end, int fuel, vector<int>& locations){
        
       if(fuel < 0) return 0;
        
        if (dp[ind][fuel] != -1)
            return dp[ind][fuel];
        
        long ans = 0;
        if(ind == end && fuel >= 0){
            // cout<<fuel<<endl;
            ans++;
        }
        for(int i=0; i<locations.size(); i++){
            if(ind == i) continue;
            
            int wt = abs(locations[ind] - locations[i]);
            // check for fuel condition to go next 
            ans = (ans + dfs(i, end, fuel-wt, locations)) % mod;
                
        }
        
        return dp[ind][fuel] = ans;
        
    }
    
    
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return dfs(start,finish,fuel, locations);
        // return cnt;
    }
};