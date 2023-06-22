//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    map<char, int> mp;
    // to store freq of unique chars
    // cout<<mp.size()<<endl;
    int n = s.size();
    int i=0, j = 0,ans = 0;

    while( j < s.size()){
        mp[s[j]]++;
        if( mp.size() < k ){
            // cout<<mp.size()<<endl;
            // mp[s[j]]++;
            j++;
        }
        else if(mp.size() == k){
            // int tot_len = 0;
            // cout<<j<<" end "<<i<< " strat "<<endl;
            // for(auto it : mp){
            //     cout<<it.first;
            //     }
            // cout<<j<<" j "<<i<<" i ";
            //     cout<<endl;
            ans = max(ans,j-i+1);
            j++;
        }
        else if(mp.size() > k){
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        
    }
    
    return (ans != 0) ? ans : -1 ;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends