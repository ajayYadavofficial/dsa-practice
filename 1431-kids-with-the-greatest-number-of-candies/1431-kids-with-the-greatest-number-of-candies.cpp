class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int k) {
        int maxi = 0;
        for(auto it : nums) maxi = max(maxi,it);
        vector<bool> ans (nums.size(),0);
        
        for(int i =0 ; i< nums.size(); i++){
            if(nums[i]+k >= maxi) ans[i] = true;
        }
        return ans;
    }
};