class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, current = 0, farthest = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, nums[i] + i);
            if(i == current){
                current = farthest;
                count++;
            }
        }
        return count;
        
    }
};