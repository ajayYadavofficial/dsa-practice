class Solution {
public:
    int minOperations(int n) {
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=(2*i+1);
        }
        int mid=n/2;
        if(n%2!=0){
            int diff=0;
            for(int i=0;i<arr.size();i++){
                diff+=abs(arr[mid]-arr[i]);
            }
            return (diff/2);
        }
        else{
            int diff=0;
            for(int i=0;i<arr.size();i++){
                diff+=abs((arr[mid]-1)-arr[i]);
            }
            return (diff/2);
        }
        
        
    }
};