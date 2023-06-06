// class Solution {
// public:
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
//         unordered_map<int,vector<int>> manages;
//         // <manager, employee>
//         for(int i=0; i<n;i++){
//             int mngr = manager[i];
//             // employee is (I)
//             if(mngr == -1) continue;
//             manages[mngr].push_back(i);
//         }
        
//         queue<pair<int,int>> q;
//         // node,timeTillNow
//         q.push({headID,0});
//         int timeTaken = 0;
//         while(!q.empty()){
//             auto it = q.front();
//             int head = it.first;
//             int headTime = it.second;
//             q.pop();
//             if(manages[head].size() == 0) timeTaken = headTime;
//                 for(auto subOrdinates : manages[head]){
//                     q.push({subOrdinates, headTime+informTime[head]});
//                 }
            
//         }
        
        
//         // for (auto it : manages){
//         //     cout<<it.first<<endl;
//         //     for(auto it2 : it.second){
//         //         cout<<it2<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
        
//         return timeTaken;
//     }
// };


class Solution {
public:
    int dfs(int headId,vector<int>& informTime,vector<int> adj[]){

        int maxTime = 0;

        for(auto it:adj[headId])
           maxTime = max(maxTime,dfs(it,informTime,adj));

        return informTime[headId] + maxTime;   
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
            vector<int> adj[100005];

            for(int i=0;i<manager.size();i++)
                if(manager[i] != -1)
                  adj[manager[i]].push_back(i);
            
        return dfs(headID,informTime,adj);    
    }
};
