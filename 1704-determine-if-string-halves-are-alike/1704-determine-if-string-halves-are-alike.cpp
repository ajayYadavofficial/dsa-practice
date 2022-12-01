class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.size();
        int l=0,r=n-1,lcnt=0,rcnt = 0;
        
        while( l < r){
            if(s[l] =='a'||s[l] == 'e'|| s[l] == 'i'|| s[l] == 'o' || s[l] == 'u'
               || s[l] == 'A'|| s[l] == 'E' || s[l] == 'I' || s[l] == 'O'|| s[l] == 'U' ) lcnt++;
            
            if(s[r] =='a'||s[r] == 'e'|| s[r] == 'i'|| s[r] == 'o' || s[r] == 'u'
               || s[r] == 'A'|| s[r] == 'E' || s[r] == 'I' || s[r] == 'O'|| s[r] == 'U') rcnt++;
            
            l++;
            r--;
        }
        return lcnt == rcnt;
    }
};