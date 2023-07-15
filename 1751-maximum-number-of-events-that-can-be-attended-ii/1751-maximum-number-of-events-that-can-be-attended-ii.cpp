class Solution {
public:
    
    
    int solve( int ind,vector<vector<int>>& events, int k, map<pair<int,int>, int> &dp){
        
        if( k == 0 || ind >= events.size() ) return 0;
        // not take
        
        if(dp.find({ind,k}) != dp.end()) return dp[{ind,k}];
        int notTake = 0 + solve( ind+1, events, k, dp );
        int i;
        // for(i = ind+1; i < events.size(); i++){
        //     if( events[ind][1] < events[i][0] ) break;
        // }
        
        vector<int> temp = { events[ind][1], INT_MAX, INT_MAX };
        i = upper_bound(events.begin() + ind -1 , events.end(), temp) - events.begin();
        
        int take = events[ind][2] + solve( i , events, k-1 ,dp);
        return dp[{ind,k}] =  max(take, notTake);
        
    }
    
    /*int binarySearch( int nextStart, vector<vector<int>>& events ){
        int n = events.size();
        int l = 0, r = n-1;
        int ansIndx = 0;
        while( l <= r){
            
            int mid = ( l + r )/2;
            
            if( events[mid][0] < nextStart ){
                r = mid-1;
            }
            else if( events[mid][0] > nextStart ){
                l = mid+1;
            }
            else{
                ansIndx = mid;
                break;
            }
            
        }
        return ansIndx;
        
    }*/
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        map<pair<int,int>, int> dp;
        
        // for(auto it : events){
        //     for(auto it1 : it){
        //         cout<<it1<<" ";
        //     }
        //     cout<<endl;
        // }
     return solve( 0 , events, k, dp);  
    }
};