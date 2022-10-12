class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2,vector<vector<int>> &dp ){
        
        if(i == 0) return j;
        if(j == 0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
//         match
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 0 + f(i-1,j-1,s1,s2,dp);
        
//         not Match
        int insert = 1 + f(i, j-1, s1,s2,dp);
        int remove = 1 + f(i-1, j, s1,s2,dp);
        int replace = 1 + f(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min(insert, min(remove, replace));
    }
    
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        // vector<vector<int>> dp (n+1, vector<int>(m+1, -1));
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0));
        
        for(int j = 0; j<=m; j++) dp[0][j] = j; 
        for(int i = 1; i<=n; i++) dp[i][0] = i;// filling from 1 becoz 0 th case of i is already taken care of
        
        for(int i= 1; i<=n;i++){
            for(int j=1; j<=m; j++){
                
                if(s1[i-1] == s2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
        
        //         not Match
                else{
                int insert = 1 + dp[i][j-1];
                int remove = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min(insert, min(remove, replace));
                }
                
            }
        }
        
        return dp[n][m];
        
    }
};