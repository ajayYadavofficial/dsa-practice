//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        // deque<int> q; // queue
        // q.push_back(arr[0]);
        // vector<int> ans;
        // for(int i=0, j=0; i< n-k+1; i++){
            
        //     while(j-i < k){
        //         while( !q.empty() && q.back()<arr[j]){
        //             q.pop_back();
        //         }
        //         q.push_back(arr[j]);
        //         j++;
        //     }
        //     ans.push_back(q.front());
        //     if(arr[i] == q.front()) q.pop_front();
        // }
        
        // return ans;
        
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            // if the front element of the deque is the index i - k then its out of the window
            // so we will have to pop the front most element
            if (dq.front() == i - k) dq.pop_front();
            // we are storing indices in dq.
            // while nums[last_indice_stored] < nums[i], we will have to pop the last element
            while (!dq.empty() && arr[dq.back()] < arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i); // pushing index
            if (i >= k - 1) res.push_back(arr[dq.front()]); // finding res array as ans
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends