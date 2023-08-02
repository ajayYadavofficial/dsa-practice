class Solution {
public:
    
    void solve(int n,vector<int>& nums, vector<vector<int>> &ans, vector<int> &smallAns, 
              vector<bool> &mark){
        
        if( smallAns.size() == n ){
            ans.push_back(smallAns);
            return;
        }
        
        
        for(int i = 0; i< n; i++){
            
            if(!mark[i]){
                
                mark[i] = 1;
                smallAns.push_back(nums[i]);
                solve(n,nums,ans,smallAns, mark);
                mark[i] = 0;
                smallAns.pop_back();
            }
            
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> smallAns;
        vector<bool> mark(nums.size(), 0);
        
        solve(nums.size(), nums, ans, smallAns, mark);
        return ans;
        
    }
};