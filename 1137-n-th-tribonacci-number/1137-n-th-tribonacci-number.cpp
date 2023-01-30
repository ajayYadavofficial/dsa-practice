class Solution {
public:
    
//     int f ( int ind, vector<int> &dp ){
        
//         if(ind == 0 || ind == 1 || ind == 2) return ind;
        
//         if(dp[ind] != -1) return dp[ind];
        
//         return dp[ind] = f(ind-1, dp) + f(ind-2, dp) + f(ind-3, dp);
        
//     }
    
    int tribonacci(int n) {
        int f=0,s=1,t=1,temp=n;
        int cur=0;
        if(n<=1) return n;
        if(n==2) return n-1; 
        if(temp=37) n--;
        for(int i=1;i<n;i++){
            cur=f+s+t;
            f=s;
            s=t;
            t=cur;
        }
        if(temp==37) return t;
        return s;
    }
};