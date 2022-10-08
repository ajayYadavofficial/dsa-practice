class Solution {
public:
    
    void f(int ind,int n,  vector<int>& nums, vector<vector<int>> &ans ){
        
        if( ind >= n){
            
            for(int i = 0;i<ans.size();i++){
                if(ans[i]==nums)
                    return;
            }
            
            ans.push_back(nums);
            return;
            
        }
        
        
        for(int i = ind; i<n;i++){
            swap(nums[ind], nums[i]);
            f(ind+1, n,nums,ans);
            swap(nums[ind], nums[i]);
        }
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        f(0, n, nums, ans);
        return ans;
        
    }
};