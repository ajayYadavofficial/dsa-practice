class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for(int j=0;j<m;j++){
            ans[j] = j;
        }
        for(int j = 0; j< m; j++){
            int posj= j;
            for(int i =0; i<n ;i++){
                
                if(grid[i][posj] == 1){
                    // ball going check my right side
                    if(posj+1 >= m || grid[i][posj+1] == -1 ) {
                        ans[j] = -1;
                        break;
                    }
                    posj = posj+1;
                    ans[j] = posj;
                    
                }
                
                else if(grid[i][posj] == -1){
                    // ball going left check its left
                    if(posj-1 < 0 || grid[i][posj-1] == 1 ) {
                        ans[j] = -1;
                        break;
                    }
                    posj = posj -1;
                    ans[j] = posj;
                }
                if(j == 0) cout<<i<<" "<<posj<<endl;
            }
        }
        return ans;
    }
};