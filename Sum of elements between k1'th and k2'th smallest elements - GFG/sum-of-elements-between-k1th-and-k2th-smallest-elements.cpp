//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
#define ll long long

class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        priority_queue<ll> pq;
        
        for(ll i=0; i<N; i++){
            pq.push(A[i]);
            if(pq.size() > K2){
                pq.pop();
            }
            
        }
        pq.pop();
        ll cnt = K2-K1-1;
        ll ans = 0;
        while(cnt){
            // cout<<"top element ="<<pq.top()<<endl;
            ans += pq.top();
            pq.pop();
            cnt--;
        }
        return ans;
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