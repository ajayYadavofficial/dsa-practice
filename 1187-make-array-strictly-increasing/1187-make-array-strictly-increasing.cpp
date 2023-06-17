class Solution {
public:
    
    int solve(map<pair<int,int>,int> &dp, int i, int prev,vector<int>& arr1, vector<int>& arr2 ){
        
        if( i == arr1.size()) return 0;
        
        if(dp.find({i,prev}) != dp.end()) return dp[{i,prev}];
        
        int ind = upper_bound(arr2.begin(), arr2.end(), prev ) - arr2.begin();
        int ans = INT_MAX/2;
        // not replace
        if(arr1[i] > prev) ans = min(ans , solve(dp, i+1, arr1[i], arr1, arr2));
        
        if( ind < arr2.size() ) ans = min (ans , solve(dp, i+1, arr2[ind], arr1, arr2) + 1);
        
        return dp[{i,prev}] = ans;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        
        map<pair<int,int>,int> dp;
        //  < <indx(i), prev>, value>
        int ans = solve(dp,0,INT_MIN,arr1,arr2);
        return ans >= INT_MAX/2 ? -1 : ans ;
    }
};