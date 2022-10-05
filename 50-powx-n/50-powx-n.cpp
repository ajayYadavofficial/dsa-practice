class Solution {
public:
    double solve(double x,long long n){
        if(n==0) return 1;
        return n%2 ? x*solve(x*x,n>>1):solve(x*x,n>>1);
    }
    
    double myPow(double x, int n) {
        if(n<0) {
            long long n1=n;
            n1=-n1;
            x=1/x;
            return solve(x,n1);
        }
        return solve(x,n);
    }
};