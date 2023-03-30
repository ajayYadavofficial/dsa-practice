class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int res = 0;
        for(char c1 = 'a'; c1 <= 'z'; c1++ ){
            
            for(char c2 = 'a'; c2 <= 'z'; c2++){
                if( c1 == c2) continue;
                int cnt1 = 0, cnt2 = 0, flg = 0; 
                for(auto it : s){
                    if( c1 == it) cnt1++;
                    if( c2 == it) cnt2++;
                    
                    if(cnt2 > cnt1) {
                        cnt2 = 0;
                        cnt1 = 0;
                        flg = 1;
                    }
                    else if(cnt2 == 0 && flg) {
                        res = max(res, cnt1 - 1);
                    }
                    else if(cnt2 > 0) {
                        res = max(res, cnt1 - cnt2);
                    }
                    
                }
                
            }
            
        }
        return res;
    }
};