class Solution {
public:
    
//     int f(int i,int j, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp){
        
// //         base case to stop
//         if(i >= n-1) return matrix[n-1][j];
        
        
//         if(dp[i][j] != -1) return dp[i][j];
        
// //         cases
// //         left down
//         int leftDia = INT_MAX, rightDia = INT_MAX;
//         if(j-1 >= 0){
//              leftDia = matrix[i][j] + f(i+1, j-1, matrix,n,dp);
//         }
// //         right Down
//         if(j+1 < n){
//             rightDia = matrix[i][j] + f(i+1, j+1, matrix,n,dp);
//         }
        
// //         down
//         int down = matrix[i][j] + f(i+1, j, matrix,n,dp);
        
        
//         return dp[i][j] = min(leftDia, min(rightDia,down));
        
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        /*MEMOIZATION*/
//         int n = matrix.size();
//         int ans = INT_MAX;
//         vector<vector<int>> dp (n, vector<int>(n,-1));
        
        
//         for(int j= 0;j<n;j++){
//         /*becoz there are variabel starting point so we have to compute for each stating point in the 1st row therefore we are calling recursion for each element of 1st row*/
//             int currans = f(0,j,matrix,n,dp);
//             if(currans < ans) ans = currans;
//         }
//         return ans;
        
        
        /*TABULATION*/
        
        int n = matrix.size(), m = matrix[0].size() , ans = INT_MAX;

		for(int i = 1; i < n; i++){
			for(int j = 0; j < m; j++){
				if(j == 0){
					matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
				}
				else if(j == m-1){
					matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j-1]);
				}
				else
				matrix[i][j] += min(matrix[i-1][j] , min(matrix[i-1][j-1] , matrix[i-1][j+1]));
			}
		}

		for(int j = 0; j < m; j++){
			ans = min(ans,matrix[n-1][j]);
		}

		return ans;
    }
};