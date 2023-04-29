class Solution {
public:
    
    void dfs(int i, vector<string>& strs, vector<bool> &visi){
        visi[i] = true;
        for(int j=0; j<strs.size(); j++){
            if(visi[j]) continue;
            if(is_similar(strs[i], strs[j]) ){
                dfs(j,strs,visi);
            }
        }
    }
    
    bool is_similar(string s1, string s2){
        int diff = 0;
        for(int i=0; i<s1.size();i++){
            if(s1[i] != s2[i]) diff++;
            if(diff > 2) return false;
        }
        return (diff == 0 || diff == 2);
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int groups = 0; 
        int n = strs.size();
        vector<bool> visi(n,0);
        
        
        for(int i=0; i<n;i++){
            if(visi[i]) continue;
            groups++;
            dfs(i,strs,visi);
        }
        return groups;
    }
};