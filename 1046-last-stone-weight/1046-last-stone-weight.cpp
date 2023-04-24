class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1 ) return stones[0];
        int n = stones.size();
        priority_queue<int> pq;
        for(auto it : stones) pq.push(it);
        
        while(pq.size() != 1 && !pq.empty()){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if( x != y) pq.push(y-x);
        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};