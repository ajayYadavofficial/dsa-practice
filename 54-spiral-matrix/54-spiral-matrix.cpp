class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        cout<<rows<<cols<<endl;
        
        int minRow = 0, minCol = 0, maxRow = rows-1, maxCol = cols-1;
        int tec = rows*cols; // total element count 
        int cnt = 0;
        
        while(cnt < tec){
            // top wall
            
            for (int i= minCol; i<= maxCol && cnt<tec; i++){
                ans.push_back(matrix[minRow][i]);
                cnt++;
            }
            minRow++;
            
            // right Wall
            for (int i= minRow; i<= maxRow && cnt<tec; i++){
                ans.push_back(matrix[i][maxCol]);
                cnt++;
            }
            maxCol--;
            
            // bottom wall
            for (int i= maxCol; i>= minCol && cnt<tec; i--){
                ans.push_back(matrix[maxRow][i]);
                cnt++;
            }
            maxRow--;
            
            // leftWall
            
            for (int i= maxRow; i>= minRow && cnt<tec; i--){
                ans.push_back(matrix[i][minCol]);
                cnt++;
            }
            minCol++;
            
            
        }
        
        
        
        
        return  ans;
    }
};