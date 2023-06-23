class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128);
        int len = t.size(),mn = INT_MAX, left = 0,start = 0,i = 0;
      
        for(int i = 0;i<len;i++)cnt[t[i]]++;
        
        while(i<=s.size() and start < s.size()){
            if(len){
                 if(i == s.size())break;
                 cnt[s[i]]--;
                 if(cnt[s[i++]] >=0)--len;
            }else{
                if(i-start < mn)mn = i-start,left = start;
                
                cnt[s[start]]++;
                if(cnt[s[start++]]>0)++len;
            }
        }
        return mn == INT_MAX ? "":s.substr(left,mn);
    }
};