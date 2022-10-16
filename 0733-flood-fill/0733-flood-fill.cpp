class Solution {
public:
    
    void f(int i, int j, int color,vector<vector<int>>& image, int srcColor ){
        
        if( j <0 || j >= image[0].size() || i<0 || i>=image.size() ||image[i][j] == color) return ;
        if(image[i][j] != srcColor) return;
        
//         if i am here that means the curr indx xolor is same as src color
        image[i][j] = color;
//         move up
        f(i,j-1,color,image, srcColor);
//         move down
        f(i,j+1,color,image, srcColor);
//         move left
        f(i-1,j,color,image, srcColor);
//         move right
        f(i+1,j,color,image, srcColor);
        
        return ;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int srcColor = image[sr][sc];
        f(sr,sc, color,image,srcColor);
        return image;
    }
};