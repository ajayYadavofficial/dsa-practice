class Solution {
public:
    
    void putzero (int i, int j, vector<vector<int>> & mat){
        for( int k = 0; k< mat.size(); k++){
            mat[k][j] = 0;
        }
        for(int k =0 ; k<mat[0].size(); k++){
            mat[i][k] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> mark(row, vector<int>(col, 0));
        
        for(int i =0; i< row; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == 0)
                    mark[i][j] = 1;
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(mark[i][j] == 1){
                    putzero(i,j,matrix);
                }
            }
        }
        
    }
};