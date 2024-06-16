// class Solution {
// public:
    
//     // sum of elemtents in an array can = K
//     // for loop on N
//     // if sum not possible then add the min-diff that is required to fill in
//     // do not search the whole array, do a Binary Search to find Kth lower Bound 
    
//     int isSumKPossible (vector<int>& nums, int k, int ind, int len){ // add the functionality to find in specific range
        
//         if(ind >= len){
//             return K;
//         }
        
//         if( k == 0 ){
            
//         }
        
//         // pick
//         int pick = 0;
        
//         if(nums[ind] <= k){
//             pick = isSumKPossible(nums, k-nums[ind], ind+1, len);
//         }
        
//         int notPick = isSumKPossible(nums, k, ind+1, len);
        
//         return 
//         // not pick
//     }
    
    
//     int minPatches(vector<int>& nums, int n) {
        
//     }
// };


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long ans = 0, sum = 0;
        for(int i = 0; i < nums.size() && sum < n; i++) {
            if(nums[i] <= sum + 1) {
                sum += nums[i];
            } else {
                i--;
                ans++;
                sum = sum * 2 + 1;
            }
        }
        while(sum < n) {
            sum = sum * 2 + 1;
            ans++;
        }
        return ans;
    }
};