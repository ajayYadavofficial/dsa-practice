class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        // vector<vector<int>> ans;
        sort( nums.begin(), nums.end());
       
        int i =0;
        int j = 1;
        while( j < n ){
            
            int prev_st = nums[i][0];
            int prev_end = nums[i][1];
            int curr_st = nums[j][0];
            int curr_end = nums[j][1];
            
            if( prev_end >= curr_st && prev_end < curr_end){
                // merge the cells
                nums[i][1] = curr_end;
                nums.erase(nums.begin() + j);
                n = nums.size();
            }else if(prev_end >= curr_st && prev_end >= curr_end){
                nums.erase(nums.begin() + j);
                n = nums.size();
            }
            else{
                i = j;
                j++;
            }
            
        }
        return nums;
    }
};