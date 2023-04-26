class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        vector<vector<bool>>dp(s1.length()+1,vector<bool>(s2.length()+1,false));
        dp[0][0]=true;
        for(int i=1;i<=s1.length();i++){
            dp[i][0]=dp[i-1][0] && s1[i-1]==s3[i-1];
        }
        for(int i=1;i<=s2.length();i++){
            dp[0][i]=dp[0][i-1] && s2[i-1]==s3[i-1];
        }
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                dp[i][j]=(dp[i-1][j] && s1[i-1]==s3[i+j-1])|| (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};


//Recursive solution
// class Solution {
// public:
//     bool canMake(string s1,string s2,string s3,int i,int j,int k){
//         if(i==s1.length() && j==s2.length() && k== s3.length())return true;
//         if(i<s1.length() && s1[i]==s3[k] && canMake(s1,s2,s3,i+1,j,k+1))return true;
//         if(j<s2.length() && s2[j]==s3[k] && canMake(s1,s2,s3,i,j+1,k+1))return true;
//         else return false;
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s1.length()+s2.length()!=s3.length())return false;
//         return canMake(s1,s2,s3,0,0,0);
//     }
// };