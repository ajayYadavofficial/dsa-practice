class Solution {
public:
    
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==0 && j==0 ) return true;
        
        if(i==0 && j> 0) return false;
        
        if(j==0 && i>0) {
            
            for(int k = 0; k<i;k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
//         match
        if(p[i-1] == s[j-1] || p[i-1] == '?'){
            return dp[i][j] = f(i-1,j-1,s,p, dp);
        }
        
//         p[i] == '*'
        if(p[i-1] == '*'){
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }
        
//         this is the case if the char is dissimilar like e<->f
        return dp[i][j] = false;
        
    }
    
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        //base cases
        dp[0][0] = true;
        // for(int j=1; j<=m,j++) dp[0][j] = false;
        for(int i=1; i<=n;i++) {
            for(int k = 0; k<i;k++){
                if(p[k] != '*') {
                    dp[i][0] = false;
                    break;
                }
                else dp[i][0] = true;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }

        //         p[i] == '*'
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

        //         this is the case if the char is dissimilar like e<->f
                else dp[i][j] = false;

            }
        }
    
        
        return dp[n][m];
    }
};