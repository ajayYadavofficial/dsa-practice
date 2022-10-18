class Solution {
public:
    
    string f(int n, string s){
        if(n == 0) return s;
        string ans = "";
        char ch = '1';
        for(int i = 0; i<s.size(); i++){
            if(s[i] == s[i+1]){
                ch++;
            }else{
                ans += ch;
                ans +=s[i];
                ch = '1';
            }
        }
        return f(n-1,ans);
    }
    
    string countAndSay(int n) {
        return f(n-1,"1");  
    }
};