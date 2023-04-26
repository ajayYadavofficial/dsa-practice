class Solution {
public:
    
    
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        if(n %2 == 0)  median = (nums[(n/2)-1] + nums[(n/2)])/2;
        int operations = 0;
        for(int i=0;i<n;i++){
            operations += abs(nums[i] - median);
        }
        return operations;
    }
};