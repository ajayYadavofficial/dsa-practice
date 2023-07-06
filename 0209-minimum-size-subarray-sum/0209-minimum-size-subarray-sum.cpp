class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window it is sub array
        int n = nums.size();
        
        int j = 0 ,sum = 0, size = INT_MAX;
        
        for(int i=0;i<n;i++){
            
            while( sum < target && j<n){
                sum += nums[j];
                j++;
            }
            // cout<<"sum = "<<sum<<" i = "<<i<<" j = "<<j<<" size = "<<j-i<<endl;
            if(sum >= target)size = min(size, j-i);
            sum -= nums[i];
            
        }
        
        return (size == INT_MAX)? 0 : size;
    }
};