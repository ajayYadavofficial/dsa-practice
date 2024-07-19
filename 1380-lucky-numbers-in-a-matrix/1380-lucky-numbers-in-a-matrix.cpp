class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // cout<<n<<" "<<m<<endl;
        vector<int> row_min (n,INT_MAX);
        vector<int> col_max (m,INT_MIN);
        vector<int> ans;
        
        for(int i = 0; i< n; i++){
            
            for(int j = 0; j < m; j++){
                row_min[i] = min(row_min[i], matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
        }
        map<int,int> mp;
        for(auto it : row_min){
            mp[it]++;
            // cout<<it<<" ";
        }
        cout<<endl;
        for(auto it : col_max){
            if(mp.find(it) != mp.end()){
                // cout<<"ans -> "<<it<<endl;
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};