class disjointset{
    public:
    vector<int>par;
    disjointset(int n){
        par.resize(n+1);
        for(int i=0; i<=n; i++){par[i]=i;}
    }
    int findp(int u){
        if(par[u]==u){return u;}
        return par[u]=findp(par[u]);
    }
    void un(int u, int v){
        par[findp(u)]=par[findp(v)];
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        disjointset d(accounts.size());
        unordered_map<string, int>m;
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else{
                    d.un(i, m[accounts[i][j]]);
                }
            }
        }
        vector<string>v[accounts.size()];
        vector<vector<string>>ans;
        for(auto it: m){
            v[d.findp(it.second)].push_back(it.first);
        }
        for(int i=0; i<accounts.size(); i++){
            if(v[i].size()==0){continue;}
            sort(v[i].begin(), v[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: v[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};