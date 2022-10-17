class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        // Sorting: to leverage the transitive property!
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initializing the DP and CHILD arrays
        vector<int> dp(n, 1), child(n, -1);
        
        int imax = 0;
        
        for(int i = 1; i < n; i++) {
            
            // Considering ith element as the last element
            // and finding the largest subset it can 
            // belong to
            for(int j = 0; j < i; j++) {
                
                // Using transitivity, if nums[i] % nums[j] == 0
                // then all numbers in the subset ending at j
                // will divide num[i] as well!
                if(nums[i] % nums[j] == 0) {
                    
                    // Inclusion of i will increase the size of 
                    // the subset by 1
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        
                        // Setting the predecessor of i
                        child[i] = j;
                    }
                }
            }
            
            // Determining the index where the largest subset ends
            if(dp[i] > dp[imax]) {
                imax = i;
            }
        }
        
        vector<int> ans;
        
        // Backtracking to obtain the entire largest subset!
        // This condition makes sure that the loop stops
        // once the first element of the subset is traversed
        while(imax != -1) {
            ans.push_back(nums[imax]);
            imax = child[imax];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};