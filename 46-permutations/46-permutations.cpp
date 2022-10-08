class Solution {
public:
    
    void f( int n, vector<int>& nums, vector<vector<int>> &ans,vector<int> &ds,vector<bool> freq   ){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }
        
        for(int i=0; i<n;i++){
            
            if(!freq[i]){
                freq[i] = true;  // marked
                ds.push_back(nums[i]); // added in ds
                f(n,nums,ans, ds, freq);
                ds.pop_back();  // removed
                freq[i] = false; // unmarked
            }
            
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq ( n, 0 );
        
        f(n, nums, ans, ds, freq );
        
        return ans;
    }
};