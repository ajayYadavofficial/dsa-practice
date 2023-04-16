class Solution {
private:
    void makeContri(int node,vector<int>& curr,vector<int>& contri,int end,vector<vector<int>>& g,int p){
        curr.push_back(node);       //this node is present in the traversal
        if(end==node){              //we reached the required end node! 
            for(auto& i:curr)   contri[i]++;   
            curr.pop_back();
            return;
        }
        for(auto& ch:g[node])   if(ch!=p)    makeContri(ch,curr,contri,end,g,node);
        curr.pop_back();        // pop the current node. 
    }
    int dp[51][2];      // dp[i][j] for the ith node if it's parent was halved or not! 
    int dfs(vector<int>& contri,vector<int>& pr,int node,vector<vector<int>>& g,int p=-1,bool parentHalved=false){
        int res1=(contri[node]*pr[node])/2,res2=contri[node]*pr[node];
        
        if(dp[node][parentHalved]!=-1)   return dp[node][parentHalved];
        
        for(auto& ch:g[node])   if(ch!=p)   res2+=dfs(contri,pr,ch,g,node,0);
        if(parentHalved) return dp[node][parentHalved]=res2;      // can't halve this node if parent was halved!
        
        for(auto& ch:g[node])   if(ch!=p)    res1+=dfs(contri,pr,ch,g,node,1);
        return dp[node][parentHalved]=min(res1,res2);
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        memset(dp,-1,sizeof dp);
        for(auto& e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> contri(n,0);        // number of times each node is traversed
        for(auto& t:trips){
            vector<int> curr;
            makeContri(t[0],curr,contri,t[1],g,-1);
        }// contribution of each node has been stored! 
        
        return dfs(contri,price,0,g,-1,0);
        
    }
};