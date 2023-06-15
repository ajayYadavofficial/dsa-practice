class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string,int> mp;
        for(int row=0; row<n; row++){
            string st = "";
            for(int col = 0; col < n; col++){
                
                st += to_string(grid[row][col]) + ",";
                
            }
            
            mp[st]++;
        }
        
        int ans = 0;
        for(int row=0; row<n; row++){
            string st = "";
            for(int col = 0; col < n; col++){
                
                st += to_string(grid[col][row]) + ",";
                
            }
            
            if(mp[st]){
                ans += mp[st];
            }
        }
        
        return ans;
    }
};