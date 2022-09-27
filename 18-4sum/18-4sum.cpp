class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            for(int j = i+1; j<n-2; j++){
                
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                
                int start = j+1, end = n-1;
                long tempTarget = (long)target - (nums[i]+nums[j]);
                while(start < end){
                    long tempSum = nums[end]+nums[start];
                    if(tempSum < tempTarget){
                        start++;
                    }else if(tempSum > tempTarget){
                        end--;
                    }else{
                        ans.push_back( {nums[i], nums[j], nums[start], nums[end] });
                        while(start < end && nums[end] == nums[end-1])
                            end--;
                        while(start < end && nums[start] == nums[start+1])
                            start++;
                        start++; end--;
                    }
                }
            }
        }
        return ans;
    }
};