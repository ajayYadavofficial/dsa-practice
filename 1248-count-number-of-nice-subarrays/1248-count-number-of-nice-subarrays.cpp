class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freqPreSum;
        freqPreSum[0]=1;
        int preSum = 0,ans =0;
        for(int i=0; i<n;i++){
            preSum += (nums[i]%2 == 0) ? 0:1;
            ans += freqPreSum[preSum - k];
            freqPreSum[preSum]++;
        }
        return ans;
    }
};