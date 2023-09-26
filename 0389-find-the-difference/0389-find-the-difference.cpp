class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        
        for(auto it:s){
            c ^= it;
        }
        for(auto it: t){
            c ^= it;
        }
        return c;
    }
};