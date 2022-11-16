class Solution {
public:
    int reachNumber(int target) {
        // convert a -ve to +ve case
        target = abs(target);
        
        // start from N = 1;
        long N = 1;
        
        // while condition is not met, do iterate
        while(!(target <= N*(N+1)/2 && (target & 1) == ((N*(N+1)/2) & 1)))
            N++;
        
        return N;
    }
};