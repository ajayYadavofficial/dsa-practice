class Solution {
public:
    
     
    int maxSubArray(vector<int>& nums) {
        
      int curr_maxi = INT_MIN;
        int final_maxi = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(curr_maxi<0)
                curr_maxi = nums[i];
            
            else
                curr_maxi+=nums[i];
            
            final_maxi = max(final_maxi, curr_maxi);
        }
        return final_maxi;
    }
};