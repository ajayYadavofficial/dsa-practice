class Solution {
public:

    
    int maxTwoEvents(vector<vector<int>>& events) {
     
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<pair<int, pair<int,int>>> pq; // <end, <start, value>>
//         we are using Max heap pbut to work it as a min heap we just negate the elemetns -ve to make it as min heap hehe
        int maxi = 0, ans = 0;
        for(int i=0; i<n; i++){
            
            int stcur = events[i][0];
            int endcur = events[i][1];
            int valcur = events[i][2];
            // maxi = max(maxi,valcur);
            
            while(!pq.empty() && (-1* pq.top().first) < stcur){
                auto it = pq.top();
                int val = it.second.second;
                maxi = max(maxi, val );
                pq.pop();
                
            }
            ans = max(ans, maxi+valcur);
            pq.push({ -1*endcur, {stcur, valcur}});
            
        }
     return ans;   
    }
};