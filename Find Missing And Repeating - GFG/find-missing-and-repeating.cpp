//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        // using swap sort
        
        for(int i=0; i<n;i++){
            
            while(arr[i] != i+1){
                int n1 = arr[i];
                int n2 = arr[n1-1];
                if(n1 == n2) break;
                swap(arr[i], arr[n1-1]);
            }
            
        }
        int dup = 0, miss = 0;
        for(int i=0;i<n;i++){
            if(arr[i] != i+1){
                dup = arr[i];
                miss = i+1;
            }
        }
        
        
        return {dup,miss};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends