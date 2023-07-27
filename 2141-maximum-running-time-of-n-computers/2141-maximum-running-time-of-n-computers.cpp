#define ll long long

class Solution {
public:
    
    bool possible(ll x, int n, vector<int> batteries){
        
        ll sum =0;
        
        for(int i = 0; i<batteries.size(); i++){
            
            sum += batteries[i];
            
            if(sum >= x){
                sum -= x;
                // remove 1 pc as we ran 1 pc to x minutes limit
                n--;
            }
            if(n == 0) return 1;
            
        }
        
        return  0;
        
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = 0, r = LLONG_MAX, ans = 0;
        sort(batteries.begin(), batteries.end());
        while( l <= r){
            // cout<<"l= "<<l<<" r= "<<r<<endl;
            ll mid = (l+r)/2;
            // cout<<"mid = "<<mid<<endl;
            if(possible(mid, n,batteries )){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
            
        }
        
        return ans;
    }
};