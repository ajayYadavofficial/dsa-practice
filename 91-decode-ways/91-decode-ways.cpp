class Solution {
public:
     int DP[101];
    int dp(int on,string &s){
        if(on==s.size())return 1;
        if(DP[on]!=-1)return DP[on];
        
        int total=0;
        
        if(s[on]!='0')total=dp(on+1,s);
        
        if(on<s.size()-1 && s[on]!='0'){
            
                int num=(s[on]-'0')*10 + (s[on+1]-'0');
               
                if(num>=1&&num<=26) total+=dp(on+2,s);
                
        }
        return DP[on]=total;
        
    }
    
    int numDecodings(string s) {
        memset(DP,-1,sizeof DP);
        return dp(0,s); 
       
    }
};