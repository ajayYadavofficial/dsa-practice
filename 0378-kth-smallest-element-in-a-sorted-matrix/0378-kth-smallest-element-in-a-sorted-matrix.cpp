class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        for(auto it : matrix){
            for(auto it1 : it){
                maxHeap.push(it1);
                if(maxHeap.size() > k) maxHeap.pop();
            }  
        }
        return maxHeap.top();   
    }
};