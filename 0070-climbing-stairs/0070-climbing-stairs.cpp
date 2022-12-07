class Solution {
public:
    
    int helpClimb(int n){
        n = n+1;
        if(n<=1) return n;
        vector<int> vect(50, -1);
        vect[0]=0;
        vect[1] =1;
        for(int i=2;i<=n;i++){
            vect[i] = vect[i-1]+vect[i-2];
        }
        return vect[n];
        
    }
    
    int climbStairs(int n) {
        
        return helpClimb(n);
        
    }
};