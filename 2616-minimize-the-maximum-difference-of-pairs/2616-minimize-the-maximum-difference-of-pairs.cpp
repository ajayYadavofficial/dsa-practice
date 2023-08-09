class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int p) {
        int count = 0, n = nums.size();
        
        for(int i = 0; i < n-1; i++) {
            if((nums[i+1] - nums[i]) <= mid) {
                count++;
                i++;
            }
            if(count >= p) return true;
        }
        return false;
    }
    
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int s = 0, e = 1e9 + 7, ans = 0;
        
        while(s <= e) {
            int mid = (s + e) / 2;
            
            if(isPossible(mid, nums, p)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        } 
        
        return ans;
    }
};