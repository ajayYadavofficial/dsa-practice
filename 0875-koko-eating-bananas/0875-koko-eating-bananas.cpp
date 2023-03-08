class Solution {
public:
    
    bool checkAns(int mid, vector<int> &piles, int h){
        int n = piles.size();
        int i= 0;
        while(h >= 0 && i < n){
            
            if(piles[i] % mid == 0){
                h -= (piles[i]/mid);
            }else{
                h =  h -1 -(piles[i]/mid);
            }
            i++;
            
        }
        if( h >= 0 && i >= n) return true;
        return false;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int st = 1;
        int end = piles[n-1];
        int ans = INT_MAX;
        while(st <= end){
            int mid = (st+end)/2;
            if(checkAns(mid,piles,h)){
                ans = min(ans,mid);
                end = mid-1;
            }else{
                st = mid+1;
            }
            
        }
        
        // cout<< checkAns(23,piles,h);
        return ans;
    }
};