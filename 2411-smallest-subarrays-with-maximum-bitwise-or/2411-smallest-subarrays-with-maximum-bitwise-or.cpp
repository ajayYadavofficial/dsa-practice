class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        // for keeping track of last index of every bit till the ith index.
        // total bit in a data type int is 32.
        vector<int>nearest(32,-1);
        vector<int>ans(n);
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<32; j++){
                // 1<<j -> a number with only set bit at jth position.
                // nums[i]&(1<<j) checks whether jth bit is set or not of nums[i];
                
                // if jth bit of nums[i] is set then we update nearest[j] to i;
                if(nums[i]&(1<<j)){
                    nearest[j] = i;
                }
            }
            
            // initially set lastSetBit to i because we have to start our set with ith element.
            int lastSetBit = i;
			
            // now we have to find which one is the bit seted most farthest among all 32 bits. we need the index i for this bit.
            for(int j = 0; j<32; j++){
                // we keep updating lastSetBit if we get any greater "i" of set bit.
                lastSetBit = max(nearest[j],lastSetBit);
            }
            // from last set bit only we can get smallest subarray.
            // after this we get same value but our subarray size will increase.
            ans[i] = lastSetBit-i+1;
        }
        
        
        return ans;
    }
};