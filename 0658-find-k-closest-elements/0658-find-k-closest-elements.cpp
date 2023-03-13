

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> maxHeap;
        // pair<diff,element>
        for(int i=0;i<n;i++){
            int diff = abs(x-arr[i]);
            maxHeap.push({diff,arr[i]});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            int element = it.second;
            ans.push_back(element);
            maxHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};