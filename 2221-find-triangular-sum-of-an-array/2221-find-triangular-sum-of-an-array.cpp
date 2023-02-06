class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j< n-i-1; j++){
                nums[j] = nums[j]+nums[j+1];
                if(nums[j] >=10) nums[j] = nums[j]%10;
            }
        }
        return nums[0];
    }
};