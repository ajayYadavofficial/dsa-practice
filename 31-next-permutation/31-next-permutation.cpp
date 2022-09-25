class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int indx1 = -1;
        int indx2 = -1;
        
        for(int i= n-2; i>=0; --i){
            if(nums[i] < nums[i+1]) {indx1 = i; break;}
        }
        if(indx1 < 0){
            reverse(nums.begin(), nums.end());
        }else{
        
        for(int i= n-1; i>indx1; --i){
            if(nums[i] > nums[indx1]) {indx2 = i; break;}
        }
        swap(nums[indx1], nums[indx2]);
        reverse(nums.begin() + indx1 + 1, nums.end()); 
    }
        
    }
};