class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            // if the front element of the deque is the index i - k then its out of the window
            // so we will have to pop the front most element
            if (dq.front() == i - k) dq.pop_front();
            // we are storing indices in dq.
            // while nums[last_indice_stored] < nums[i], we will have to pop the last element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i); // pushing index
            if (i >= k - 1) res.push_back(nums[dq.front()]); // finding res array as ans
        }
        return res;
    }
};