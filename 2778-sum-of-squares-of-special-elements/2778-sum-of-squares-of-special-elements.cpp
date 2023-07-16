class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size(); i++){
            
            if( nums.size()  % (i+1) == 0){
                // cout<<" i = "<<i+1<<" nums[i] = "<<nums[i]<<endl;
                ans += nums[i]*nums[i];
            }
            
        }
        return ans;
    }
};