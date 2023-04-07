class Solution {
public:
    int M = 1e9+7;
    long long pow_temp(long long n){
        if(n == 1) return 2;
        long long t = pow_temp(n/2);
        if(n%2 == 0) return (t*t) % M;
        return (2 * (t*t)%M)%M;
    }
    
    int monkeyMove(int n) {
//         total number of ways 2^n - no. of ways where no cillision happend (2)
        int t = pow_temp(n)%M - 2;
        return (t < 0)? M + t: t;
    }
};