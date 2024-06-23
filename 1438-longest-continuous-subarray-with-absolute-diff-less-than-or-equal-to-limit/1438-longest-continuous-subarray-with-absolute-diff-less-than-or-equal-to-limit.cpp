// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int n = nums.size();
//         if( n == 1) return 1;
//         set <int> st;
//         int l = 0, r = 0;
        
//         while(l<= r && r < n){
//             st.insert(nums[r]);
//             if( nums[r] - st.top()  > limit){
                
//                 // traverse l till it find last pos of set
//                 // set.pop() the top element
//                 //
                
//             }
//         }
//     }
// };

class Solution {
public:
    void adjust(list<pair<int, int>>& mono, int left) {
        while(mono.size() > 0 && mono.front().second < left) mono.pop_front();
    }
    
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        list<pair<int, int>> monoMax, monoMin;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(monoMax.size() > 0 && nums[i] > monoMax.back().first) {
                monoMax.pop_back();
            }
            while(monoMin.size() > 0 && nums[i] < monoMin.back().first) {
                monoMin.pop_back();
            }
            
            monoMin.push_back({nums[i], i});
            monoMax.push_back({nums[i], i});
            
            while(true) {
                adjust(monoMin, j);
                adjust(monoMax, j);
                if(monoMax.front().first - monoMin.front().first > limit) {
                    j++;
                } else {
                    break;
                }
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};