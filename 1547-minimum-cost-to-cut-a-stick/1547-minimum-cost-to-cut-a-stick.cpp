class Solution {
public:
	int minCost(int n, vector<int>& cuts) {
		cuts.insert(cuts.begin(),0);
		cuts.insert(cuts.end(),n);
		sort(cuts.begin(),cuts.end());
		int m=cuts.size();
		vector<vector<int>> dp(m,vector<int>(m,0));
		for(int i=m-1;i>=1;i--){
			for(int j=i;j<=m-2;j++){
				int mini=1e9;
				for(int ind=i;ind<=j;ind++){
					int cost= cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
					mini=min(mini,cost);
				}
				dp[i][j]=mini;
			}
		}
		return dp[1][cuts.size()-2];
	}
};