// class Solution {
// public:
//     // long long solve(vector<int>& time,int totalTrips, int ind , int   )
    
    
//     long long minimumTime(vector<int>& time, int K) {
//         int n = time.size();
//         if(n == 1) return K * time[0];
//         sort(time.begin(), time.end());
        
//         long timeSt = 1;
//         long timeEnd = INT_MAX;
        
//         while(timeSt <= timeEnd){
//             long mid = (timeSt + timeEnd)/2;
//             long long tripSum = 0;
//             for(int i=0; i<n;i++){
//                 if(time[i] <= mid){
//                     tripSum += mid/time[i];
//                     cout<<time[i]<< " time[i] "<< tripSum<< " tripSum "<< mid/time[i]<<" currTrip"<< endl;
//                 }
//             }
//             cout<<tripSum<<" "<<endl;
//             if(tripSum == K) return mid;
//             else if(tripSum > K){
//                 timeEnd = mid-1;
//             }else if(tripSum < K){
//                 timeSt = mid+1;
//             }
            
//         }
        
//         // cout<<timeEnd<<endl;
        
//         return 0;
        
//     }
// };

class Solution {
private:
    vector<int> tripTimes;
    int numTrips;
public:
    long minimumTime(vector<int>& time, int totalTrips) {
        this->tripTimes = time;
        this->numTrips = totalTrips;
        long left = 1;
        long right = 0;
        for (int t : tripTimes) {
            right = max(right, (long)t);
        }
        right = right * numTrips;
        long ans = right;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (check(mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
    bool check(long givenTime) {
        long actualTrips = 0;
        for (int t : tripTimes) 
            actualTrips += givenTime / t;
        if(actualTrips >= numTrips)
            return true;
        return false;
    }
};