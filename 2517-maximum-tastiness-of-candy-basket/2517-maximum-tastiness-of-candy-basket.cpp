class Solution {
public:
    bool isPossible(int mid,int k ,vector<int>& price  ){
        int n = price.size();
        int cnt = 1;
        int base = price[0];
        for(int i=1; i<n;i++){
            if(cnt == k) return true;
            if( price[i] - base >= mid ){
                cnt++;
                // cout<<base<<" base1"<<endl;
                base = price[i];
                // cout<<base<<" base2"<<endl;
                // cout<<mid<<" mid used"<<endl;
            }
        }
        if(cnt == k) return true;
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int st = 0;
        int end = price[n-1] - price[0];
        int ans = 0;
        while(st <= end){
            
            int mid = (st+end)/2;
            
            if(isPossible(mid, k, price)){
                ans = mid;
                // cout<<ans<<" AnswerGot"<<endl;
                st = mid+1;
            }else{
                end = mid-1;
            }
            
        }
        // cout<<ans;
        return ans;
    }
};