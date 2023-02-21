class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set <pair<int,int>> st; // node,no. of one's in that row
        
        for(int i=0; i< mat.size(); i++){
            int cnt = 0;
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] == 1) cnt++;
            }
            st.insert({cnt,i});
        }
        vector<int> vec, ans;
        for(auto it : st){
            // cout<<it.first<<" "<<it.second<<endl;
            vec.push_back(it.second);
        }
        for(int i=0; i<k; i++){
            ans.push_back(vec[i]);
        }
        
        return ans;
        
    }
};