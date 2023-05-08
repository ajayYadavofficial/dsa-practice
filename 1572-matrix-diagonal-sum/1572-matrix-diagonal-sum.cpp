class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int diagSum = 0;
        for(int i=0; i<n; i++){
            diagSum += mat[i][i] + mat[i][n-1-i];
            if( 2*i == n-1) diagSum -= mat[i][i];
        }
        return diagSum;
    }
};