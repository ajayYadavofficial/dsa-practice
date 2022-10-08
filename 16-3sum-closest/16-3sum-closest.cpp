class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans= nums[0] + nums[1] + nums[nums.size() -1];
        for(int i=0; i<nums.size()-2; i++){
            int lo = i+1;
            int hi = nums.size()-1;
            int currSum = 0;
            
            while(lo < hi){
                currSum = nums[i] + nums[lo]+nums[hi];
                if(currSum > target) --hi;
                else ++lo;
                
                if(abs(ans - target) > abs(currSum - target)) ans = currSum;
            }
        }
        
        return ans;
    }
    
    
};