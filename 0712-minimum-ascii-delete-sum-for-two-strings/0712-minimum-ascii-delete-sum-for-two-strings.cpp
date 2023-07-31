class Solution {
public:
    
    
    vector<vector<int>> dp;
    int LCS ( int i, int j ,string &s1, string &s2, int n1, int n2 ){
        
        if( i == n1 || j == n2){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        // match
        int SUM = 0;
        
        if(s1[i] == s2[j]){
            SUM += s1[i] + LCS(i+1, j+1, s1,s2,n1,n2);
        }
        else{
            SUM += max(LCS(i,j+1, s1,s2,n1,n2), LCS(i+1, j, s1, s2, n1,n2));
        }
        
        return dp[i][j] = SUM;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        dp.assign(n1+1, vector<int>(n2+1, -1));
        int LCS_SUM = LCS(0,0,s1,s2,s1.size(), s2.size());
        
        int tot_SUM = 0;
        
        for(auto it : s1) tot_SUM += it;
        for(auto it : s2) tot_SUM += it;
        
        return tot_SUM - 2*LCS_SUM;
    }
};