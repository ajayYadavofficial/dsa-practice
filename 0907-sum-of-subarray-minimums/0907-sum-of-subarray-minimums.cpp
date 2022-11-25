class Solution {
  static constexpr int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {  
      stack<int> s; // Monotone increasing stack 
      
      int n = arr.size();
      long sum = 0;
      vector<int> dp(n); // dp[i] stores the sum of subarrays ending at i
      
      for (int i = 0; i < n; i++) {
        
        while (!s.empty() && arr[s.top()] >= arr[i]) // find the leftmost index whose value is smaller than arr[i].
          s.pop();
        
        if (s.size()) { // there is a smaller value than arr[i] to the left
          
          // smaller value at prev, adding arr[i] onto subarrys that contain arr[prev] won't change the smallest value
          // that is already computed in dp[prev]. There are (i - prev) subarrays ending at i whose smallest value is arr[i].
          int prev = s.top();
          dp[i] = dp[prev] + (i - prev)*arr[i];
          
        } else // No smaller value in arr - all subarrays ending at i have minimum value arr[i].
          dp[i] = (i+1)*arr[i];
        
        // The sum over dp will go over every subarray in arr, as each dp[i] only holds the contribution of subarrays that end
        // at index i.
        sum = (sum + dp[i]) % MOD;
        
        s.push(i); // add the index to the stack as all larger values have been removed
      }
      
      return (int) sum;
    }
};