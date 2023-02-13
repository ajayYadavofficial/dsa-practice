class Solution {
public:
    int countOdds(int low, int high) {
        // both the low and high are odds
        if( low % 2 != 0 || high % 2 != 0){
            return 1 + ((high - low) /2);
        }
        // both even 
        else {
            return (high - low ) / 2;
        }
        
    }
};