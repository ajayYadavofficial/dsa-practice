class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        // cout<<arr[0]<<" "<<arr1[0];
        vector<int> L_max(n,arr[0]) , R_min(n,arr[n-1]);
        
        for(int i=1; i<n;i++){
            L_max[i] = max(L_max[i-1], arr[i]);
        }
        for(int i = n-2; i>=0;--i){
           R_min[i] = min(R_min[i+1], arr[i]);
        }
        int res = 0;
        
        for(int i=0;i<n-1;i++){
            
            if(L_max[i] <= R_min[i+1]) res++;
            
            
        }
        
        return res+1;
    }
};