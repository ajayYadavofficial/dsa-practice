// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         // use max heap
//         // pair<int,pair<int,int>> // representing <distFromorigin,<X-cordinate,Y-cordinate>>
        
//         vector<vector<int>> ans;
//         unordered_map <int,pair<int,int>> mp;
        
//         for(int i = 0; i<points.size(); i++){
//             int x = points[i][0];
//             int y = points[i][1];
//             int dist = x*x + y*y;
            
//             mp.insert({dist,{x,y}});
//         }
        
//         priority_queue<pair<int,pair<int,int>>> maxheap;
        
//         for(auto it : mp){
//             int d = it.first;
//             int x = it.second.first;
//             int y = it.second.second;
//             maxheap.push({d,{x,y}});
//             if(maxheap.size() > k) maxheap.pop();    
//         }
        
//         while(!maxheap.empty()){
//             auto it = maxheap.top();
//             int x = it.second.first;
//             int y = it.second.second;
            
//             ans.push_back({x,y});
//             maxheap.pop();
//         }
        
//         return ans;
        
//     }
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
        for(auto it: points){
            int dis=it[0]*it[0]+it[1]*it[1];
            //cout<<dis<<endl;
            q.push({dis, {it[0], it[1]}});
        }
        vector<vector<int>>ans;
        while(k--){
            ans.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }
        return ans;
    }
};