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
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> decQ;
        std::deque<int> incQ;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];

            while (!decQ.empty() && num > decQ.back()) {
                decQ.pop_back();
            }
            decQ.push_back(num);

            while (!incQ.empty() && num < incQ.back()) {
                incQ.pop_back();
            }
            incQ.push_back(num);

            while (decQ.front() - incQ.front() > limit) {
                if (decQ.front() == nums[left]) {
                    decQ.pop_front();
                }
                if (incQ.front() == nums[left]) {
                    incQ.pop_front();
                }
                ++left;
            }

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};