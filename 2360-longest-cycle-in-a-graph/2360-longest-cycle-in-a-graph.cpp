class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size(),ans=-1;
        vector<bool> vis(n,false);
        for(int i=0;i<n;++i){
            if(vis[i]) continue;
            int cnt=0,j=i;
            unordered_map<int,int> m;
            while(j!=-1){
                if(m.find(j)!=m.end()){
                    ans=max(ans,cnt-m[j]);
                }
                if(vis[j]){
                    break;
                }
                vis[j]=true;
                m.insert({j,cnt});
                cnt++;
                j=edges[j];
            }
        }
        return ans;
    }
};