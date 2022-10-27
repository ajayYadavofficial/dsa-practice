// class Solution {
// public:
//     int shift_count (vector<vector<int>>& A, vector<vector<int>>& B){
//         int n = A.size();
//         int m = A[0].size();
//         int count = 0;
//         for(int x = 0; x<n; x++){
//             for(int y = 0; y < m; y++ ){
//                 int temp = 0;
//                 for(int i =x; i < n; i++){
//                     for(int j=y; j<n;j++){
//                         if(A[i][j] == 1 && B[i-x][j-y] == 1) temp++;
//                     }
//                     count = max(count, temp);
//                 }
//             }
//         }
//         return count;
//     }
    
//     int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
//         return max(shift_count(A,B), shift_count(B,A));
//     }
// };

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>vec_a;
        vector<pair<int,int>>vec_b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    vec_a.push_back({i,j});
                }
                if(img2[i][j]==1){
                    vec_b.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto [i1,j1]:vec_a){
            for(auto [i2,j2]:vec_b){
                mp[{i1-i2,j1-j2}]++;
                ans=max(ans,mp[{i1-i2,j1-j2}]);
            }
        }
        return ans;
    }
};