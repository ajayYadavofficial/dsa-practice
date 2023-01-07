class Solution {
public:
    int maximumTop(vector<int>& v, int k) {
        int n=v.size();
        if(n==1 && k%2==1){
            return -1;
        }
        int mx=INT_MIN;
        for(int i=0;i<n && i<k-1;i++){
            mx=max(mx,v[i]);
        }
        if(k<n){
            mx=max(mx,v[k]);
        }
        return mx;
    }
};
