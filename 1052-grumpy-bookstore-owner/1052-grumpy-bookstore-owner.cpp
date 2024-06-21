class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int preSum = 0;
        int n = grumpy.size();
        for (int i = 0; i<n; i++ ){
            if(grumpy[i] == 0){
                preSum += customers[i];
            }
        }
        int r = 0, l = 0;
        int ans = preSum;
        while(r < n ){
            if( r-l+1 <= minutes){
                // increase the window and add this [r] indx if grumpy[r] == 1
                if(grumpy[r] == 1){
                    preSum += customers[r];
                    ans = max(ans, preSum);
                }
                r++;
            }
            else {
                // move left pointer one place and remove the weight at that pointer if grumpy is 1 at that pos
                if(grumpy[l] == 1){
                    preSum -= customers[l];
                }
                l++;        
            }
        }
        return ans;
    }
};