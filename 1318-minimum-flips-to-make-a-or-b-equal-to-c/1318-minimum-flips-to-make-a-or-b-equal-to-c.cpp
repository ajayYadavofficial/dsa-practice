class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> bitA (a);
        bitset<32> bitB (b);
        bitset<32> bitC (c);
        int ans = 0;
        for(int i=0; i<32; i++){
            
            if( bitC[i] == 0){
                if(bitA[i] == 0 && bitB[i] == 0) continue;
                else if( bitA[i]*bitB[i] == 1) ans += 2;
                else ans += 1;
            }
            else {
                if(bitA[i] == 0 && bitB[i] == 0) ans += 1;
                else continue;
            }
            
        }
        
        return ans;
    }
};