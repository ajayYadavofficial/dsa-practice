// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
//         priority_queue <int, vector<int>, greater<int> > lt;
//         priority_queue <int, vector<int>, greater<int> > rt;
//         // set<pair<int,int>> st;
        
//         int i = 0, j = costs.size()-1, ans = 0;
        
//         // put first candidates in lt pq && put last candidates in rt pq
//         while( i < candidates){
//             lt.push(costs[i]);
//             i++;
//         }
        
//         while( j >= costs.size() - candidates){
//             rt.push(costs[j]);
//             j--;
//         }
        
//         // k sessions ->
        
//         for(int K = 1; K <= k ; K++){
            
//             int lt_min =  lt.top();
//             int rt_min = rt.top();
            
//             if( lt_min <= rt_min){
//                 ans += lt_min;
//                 lt.pop();
//                 if(i+1 < costs.size()) lt.push(costs[i++]);
//             }
//             else if( rt_min < lt_min){
//                 ans += rt_min;
//                 rt.pop();
//                  if(j-1 >= 0)rt.push(costs[j--]);
//             }
            
//         }
//         // cout<<ans;
//         return ans;
//     }
// };


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;

        int cnt = 0;
        int i=0;
        int j=costs.size()-1;

        while(cnt<k){

            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);

            int cost1 = pq1.size()>0?pq1.top():INT_MAX;
            int cost2 = pq2.size()>0?pq2.top():INT_MAX;

            if(cost1<=cost2){

               ans += cost1;
               pq1.pop();
            }
            else{

              ans += cost2;
              pq2.pop();
            }

            cnt++;
        }

        return ans;
    }
};