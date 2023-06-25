class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = z;
        if(x == y){
            ans += x*2;
        }
        else{
            ans += 2*min(x,y)+1;
        }
        return ans*2;
    }
};