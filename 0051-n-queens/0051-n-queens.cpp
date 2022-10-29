class Solution {
public:
    
    bool isPossible(int row, int col, vector<string> &board, int n){
        for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
		    // No need to traverse more since the lower rows below current row attribute will always be safe.
			/* if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
			if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; */
	    }
        
        return true;
    }
    
    void f(int row, vector<string> &board, vector<vector<string>> &matrix, int n){
        if(row == n){ 
            matrix.push_back(board);
            return;}
        
        for(int col =0; col< n; col++){
            if(isPossible(row, col, board, n)){
                board[row][col] = 'Q';
                f(row+1, board, matrix, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> matrix ;
        vector<string> board(n);
        string s (n, '.');
        for(int i=0; i<n;i++){
            board[i] = s;
        }
        f(0, board,matrix,n);
        return matrix;
        
    }
};