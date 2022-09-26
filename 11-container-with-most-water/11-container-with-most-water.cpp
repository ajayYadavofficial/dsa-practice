class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i = 0;
        int j= n-1;
        int maxArea = INT_MIN;
        while( i < j){
            int maxSoFar = 0;
            int maxDist = j-i;
            // cout<<"dist "<<maxDist;
            int length = min(height[i], height[j]);
            // cout<<"len "<<length<<endl;
            maxSoFar = maxDist * length;
            if(maxSoFar > maxArea ) maxArea = maxSoFar;
            
            if(height[i] < height[j])i++;
            else j--;
           
            
        }
        
        return maxArea;
        
    }
};