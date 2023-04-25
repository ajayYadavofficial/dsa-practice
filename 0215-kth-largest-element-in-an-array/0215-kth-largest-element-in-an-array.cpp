class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>, greater<int>> pq;
        int i =0;
        while(pq.size() <= k && i < nums.size()){
            pq.push(nums[i]);
            i++;
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};