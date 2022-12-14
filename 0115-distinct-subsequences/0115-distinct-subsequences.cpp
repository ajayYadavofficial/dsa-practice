class Solution {
    
public:
    
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
//         match
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = f(i-1,j-1, s1,s2, dp) + f(i-1,j,s1,s2, dp);
        }
        
//         not match
        return dp[i][j] = f(i-1, j, s1, s2, dp);
        
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp (n+1, vector<int>(m+1, -1));
        // vector<vector<double>> dp (n+1, vector<double>(m+1, 0));
        vector<double> prev(m+1, 0), cur(m+1, 0);
        
        
        // for(int i = 0; i<= n; i++) dp[i][0] = 1;
        prev[0] = cur[0] = 1;
        // for(int j = 1; j<= m; j++) dp[0][j] = 0; // not necessary to do
        
        for(int i = 1; i<=n;i++){
            for(int j = 1; j<= m;j++){
                if(s[i-1] == t[j-1]){
                   cur[j] = prev[j-1] + prev[j];
                }
        //         not match
                else{
                cur[j] = prev[j];
                } 
            }
            prev = cur;
        }
        
        // return f(n,m, s, t, dp);
        return (int)prev[m];
    }
};