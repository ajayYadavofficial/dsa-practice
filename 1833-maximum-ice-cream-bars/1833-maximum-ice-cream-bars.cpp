// class Solution {
// public:
    
//     int f(int ind,vector<int>& costs, int sum, int cnt){
//         int n = costs.size();
//         if(ind == n-1){
//             if(sum - costs[ind]) cnt++;
//             return cnt;
//         }
        
//         int notTake = f(ind +1, costs, sum, cnt);
        
//         sum = sum - costs[ind];
//         if(sum < 0){
//             return cnt;
//         }
// //         take
//         int take = f(ind + 1, costs, sum, cnt+1);        
//         return max(take, notTake);
        
        
//     }
    
//     int maxIceCream(vector<int>& costs, int coins) {
        
//         return f(0,costs,coins,0);
        
//     }
// };

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int ans = 0 , n = costs.size();
        for(int i = 0 ; i < n ; i++){
            if(costs[i] <= coins){
                ans++;
                coins -= costs[i];
            }
        }
        return ans;
    }
};