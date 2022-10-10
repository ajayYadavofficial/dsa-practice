class Solution {
public:
    
    int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp){
        
        if(ind1 < 0 || ind2 < 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2] ) return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s1, s2, dp);
        
        return dp[ind1][ind2] = 0 + max(f(ind1-1, ind2, s1, s2, dp),f(ind1, ind2-1, s1, s2, dp) );
        
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        
          int n=s1.size();
        int m=s2.size();
        
        int t[n+1][m+1];
        
        //Initialization
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0) t[i][j]=0;
            }
        }
        
        //Top dowm
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    t[i][j] = t[i-1][j-1]+1;
                }
                else {
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];
        
    }
};