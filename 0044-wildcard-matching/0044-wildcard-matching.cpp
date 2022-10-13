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
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return f(n,m,s,p, dp);
    }
};