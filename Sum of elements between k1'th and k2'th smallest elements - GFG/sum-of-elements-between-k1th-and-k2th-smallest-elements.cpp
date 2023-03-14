//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long> maxHeap;
        
        for(long long i=0; i<N;i++){
            maxHeap.push(A[i]);
        }
        
        while( maxHeap.size() >= K2){
            maxHeap.pop();
        }
        K2--;
        // cout<<maxHeap.size()<<endl;
        long long sum = 0;
        for(long long i = 1; i<=K2-K1; i++ ){
            sum += maxHeap.top();
            // cout<<maxHeap.top()<<" maxHeapTop "<<i<<endl;
            maxHeap.pop();
        }
        
        return sum;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends