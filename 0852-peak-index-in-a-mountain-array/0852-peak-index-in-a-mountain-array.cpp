class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int indx = 0;
        while(indx < arr.size() - 1){
            if(arr[indx] > arr[indx+1]){
                return indx;
            }
            indx ++;
        }
        return indx;
        
    }
};