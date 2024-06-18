class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vec;
        int n = profit.size();
        for(int i = 0; i<n;i++){
            vec.push_back({difficulty[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        // for(int i = 0; i<n;i++){
        //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
        // }
        int ans = 0;
        int maxProfit = 0;
        for (int i=0; i<worker.size(); i++){
            
            int worker_dif = worker[i];
            int maxProfit = 0;
            for(int j = 0; j< n; j++){
                if(worker_dif >= vec[j].first){
                    maxProfit = max(maxProfit, vec[j].second);
                    // cout<<maxProfit<<" "<<worker_dif<<endl;
                }else{ break;}
            }
            ans += maxProfit;
        }
        return ans;
    }
};