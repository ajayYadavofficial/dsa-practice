class Solution {
public:
    int addMinimum(string word) {
         int n = word.size();
        int ans = 0;
        for( int i=0; i<n;i++){
            if( word[i] == 'a'){
                if(i==n-1) ans += 2;
                else if( i == n-2){
                    if(word[i+1] == 'a'){
                        ans += 2;
                    }else{ ans += 1; i++;}
                }
                else {
                    if( word[i+1] == 'a' ) ans += 2;
                    else if( word[i+1] == 'b' && word[i+2] == 'c') i =i +2;
                    else {ans += 1; i++;}
                }
                
            }else if( word[i] == 'b'){
                if(i==n-1) ans += 2;
                else if( i == n-2){
                    if(word[i+1] == 'b' || word[i+1] == 'a'){
                        ans += 2;
                    }else{ ans += 1; i++;}
                }
                else {
                    if( word[i+1] == 'b' || word[i+1] == 'a' ) ans += 2;
                    else {ans += 1; i++;}
                }
                
                
            }else if ( word[i] == 'c'){
                ans += 2;
            }
        }
        return ans;
    }
};