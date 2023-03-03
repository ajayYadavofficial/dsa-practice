//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool solve1( int posAns, int k, vector<int> &nums){
        int temp = k; 
               int currStall  = nums[0];
               temp--;
              while( temp != 0 ){
                  temp -- ;
                  int indx = lower_bound(nums.begin(), nums.end(), currStall + posAns ) - nums.begin();
                //   cout << currStall + posAns << " " << indx << endl;
                  if( indx == nums.size()){
                     return false;
                  }
                  currStall = nums[indx];
              }
            return true;  
        
    }

    int solve(int n, int k, vector<int> &nums) {
    
        // Write your code here
        
        sort(nums.begin(), nums.end());
        if( k == 2){
            return nums[n-1] - nums[0];
        }
        
        // int minDiff = nums[n-1] - nums[0];
        
        int st = 0, end = nums[n-1];
        int Ans;
        
            // for(int posAns = 1; posAns <= nums[n-1]; posAns++){
            //   int temp = k; 
            //   int currStall  = nums[0];
            //   temp--;
            //   while( temp != 0 ){
            //       temp -- ;
            //       int indx = lower_bound(nums.begin(), nums.end(), currStall + posAns ) - nums.begin();
            //     //   cout << currStall + posAns << " " << indx << endl;
            //       if( indx == nums.size()){
            //          return posAns -1;
            //       }
            //       currStall = nums[indx];
                  
            //   }  
            //   Ans = posAns;
            // //   cout<<posAns;
                
            // }
            while( st <= end){
                int mid = (end + st)/2;
                if( solve1(mid, k ,nums) ){
                    Ans = mid;
                    st = mid+1;
                }
                else {
                    end = mid-1;
                }
                
            }
            
            
        
        return Ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends