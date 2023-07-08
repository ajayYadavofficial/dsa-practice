class Solution {
public:
    
    int maxFalse(string answerKey, int k){
       int n = answerKey.size();
        int l=0,r=0;
        int cnt = 0;
        int ans = 0;
        while(r<n){
            if(answerKey[r] == 'T') cnt++;
            while(cnt > k ){
                // cout<<"l = "<<l <<" r  = "<<r<<endl;
                if(answerKey[l] == 'T') cnt--;
                l++;
            }
            ans = max(r-l+1, ans);
            r++;
        }
        return ans; 
    }
    
    int maxTrue(string answerKey, int k){
        int n = answerKey.size();
        int l=0,r=0;
        int cnt = 0;
        int ans = 0;
        while(r<n){
            if(answerKey[r] == 'F') cnt++;
            while(cnt > k ){
                // cout<<"l = "<<l <<" r  = "<<r<<endl;
                if(answerKey[l] == 'F') cnt--;
                l++;
            }
            ans = max(r-l+1, ans);
            r++;
        }
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max( maxTrue(answerKey,k) ,maxFalse(answerKey,k) );
        
    }
};