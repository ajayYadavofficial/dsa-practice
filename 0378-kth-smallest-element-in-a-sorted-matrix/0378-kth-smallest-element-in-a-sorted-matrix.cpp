// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> maxHeap;
//         for(auto it : matrix){
//             for(auto it1 : it){
//                 maxHeap.push(it1);
//                 if(maxHeap.size() > k) maxHeap.pop();
//             }  
//         }
//         return maxHeap.top();   
//     }
// };

class Solution {
public:
    
    int findRank( int mid, vector<vector<int>> & mat){
        int n = mat.size();
        int i = n-1, j = 0;
        int cnt = 0;
        while(i >=0 && j < n){
            if(mat[i][j] > mid) i--;
            else{
                cnt += i+1;
                j++;
            }
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        int ans = 0;
        while( lo < hi){
            int mid = lo  + (hi-lo)/2;
            
            int rnk = findRank(mid, matrix);
            
            if(rnk < k){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};