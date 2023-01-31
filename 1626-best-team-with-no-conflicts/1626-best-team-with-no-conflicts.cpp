class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> mp;
        int n = scores.size();
        for(int i=0; i< scores.size();i++){
            mp.push_back({-ages[i], -scores[i]});
        }
        
       sort(mp.begin(), mp.end());
       //  for(auto it : mp){
       //      cout<<it.first<<" "<<it.second<<endl;
       //  }
        
        vector<int> dp (n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            
            for(int j =i; j>=0;j--){
                
                if(-mp[i].second <= -mp[j].second){
                    dp[i] = max(dp[i],dp[j] - mp[i].second);
                }
                
            }
            ans = max(ans,dp[i]);
            
        }
        
        
        return ans;
    }
};