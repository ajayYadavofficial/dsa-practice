// class Solution {
// public:
    
//     // maximixe the minimum I'll do the BS
    
//     bool agarPossible( int mid,vector<int>& position, int m ){
//         // (index + m is there in the array) do a lower bound as we have already sorted the position array
        
//     }
    
//     int maxDistance(vector<int>& position, int m) {
//         int n = position.size();
//         sort(position.begin(), position.end());
//         int l =1, r = position[n-1], ans = INT_MIN;
//         // agar possible the move to the right side,
//         while( l <= r){
//             int mid = l + ((r-l)/2);
//             if(agarPossible(mid, position, m)){
//                 ans = max(ans, mid);
//                 // search right
//                 l = mid+1;
//             }else{
//                 // search left
//                 r = mid-1;
//             }
//         }
//     }
//     return ans;
    
// };

class Solution {
public:
    bool agarPossible(int mid, vector<int>& position, int m) {
        int count = 1; // Place the first ball at the first position
        int last_pos = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last_pos >= mid) {
                count++;
                last_pos = position[i];
            }
            if (count >= m) {
                return true;
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 1, r = position[n-1] - position[0], ans = 0;
        
        while (l <= r) {
            int mid = l + ((r - l) / 2);
            if (agarPossible(mid, position, m)) {
                ans = mid;
                l = mid + 1; // search right
            } else {
                r = mid - 1; // search left
            }
        }
        return ans;
    }
};
