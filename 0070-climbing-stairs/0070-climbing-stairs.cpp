class Solution {
public:
    
//     int helpClimb(int n){
//         n = n+1;
//         if(n<=1) return n;
//         vector<int> vect(50, -1);
//         vect[0]=0;
//         vect[1] =1;
//         for(int i=2;i<=n;i++){
//             vect[i] = vect[i-1]+vect[i-2];
//         }
//         return vect[n];
        
//     }
    
    
    int helpClimb(int ind, vector<int> &dp){
        if(ind == 0) return 1;
        if(ind == 1) return 1;
        if(dp[ind] != -1 ) return dp[ind];
        int step1 = helpClimb( ind - 1, dp);
        
        int step2 = helpClimb(ind - 2, dp);
        
        return dp[ind] = step1 + step2;
        
    }
    
    int climbStairs(int n) {
        vector<int> dp (n+1,-1);
        return helpClimb(n, dp);
        
    }
};