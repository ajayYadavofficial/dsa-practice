class Solution {
public:
    int search(vector<int>& arr, int k) {
       int n = arr.size();
        int L = 0;
        int R = n-1;
        int mid;
        while( L <= R){
            mid = (L+R)/2;
        if( arr[mid] == k) return mid;
        else if(arr[mid] >=  arr[L] ){
            if( k <= arr[mid] && k >= arr[L]){
                R = mid -1;
            }else{
                L = mid+1;
            }
        }
        else{
            if( k >= arr[mid] && k <= arr[R]){
                L = mid+1;
            }else{
                R = mid-1;
            }
        }
        
        }
        
        return -1;
    }
};