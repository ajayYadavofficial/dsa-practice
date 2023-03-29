class Solution {
public:
    
//     int f(int ind, int time,vector<int>& arr ){
//         int n = arr.size();
//         if(ind == n-1){
//             // base
//             return arr[ind];
//         }
        
//         // pick 
//         int p = arr[ind]*time + f(ind+1,time +1, arr);
        
//         // not pick
//         int np = 0 + f(ind +1, time, arr);
//         cout<<p<<" p "<<np<<" np "<<endl;
//         return max(p,np);
        
//     }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());
        if(satisfaction[0] <= 0) return 0;
        int max_time = n;
        int maxi = 0;
        for(int i=1; i<= n; i++ ){
            int currSum = 0;
            int cnt = 0;
            for(int j = i; j>=1; j--){
                // cout<<i<<" i"<<endl;
                currSum += satisfaction[cnt]*j;
                cnt++;
            }
            maxi = max(maxi,currSum);
        }
        return maxi;
    }
};