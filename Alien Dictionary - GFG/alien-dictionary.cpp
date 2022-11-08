//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<int> topoSort (vector<int> adj[], int K){
        
        vector<int> topo;
        queue<int> Q;
        vector<int> indegree(K,0);
        
        for(int i=0; i<K;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<K;i++){
            if(indegree[i] == 0){
                Q.push(i);
            } 
        }
        
        while(!Q.empty()){
            int node = Q.front();
            topo.push_back(node);
            Q.pop();
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] ==0){
                    Q.push(it);
                }
            }
            
        }
        return topo;
        
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj [K];
        
        // get our graph prepared
        for(int i =0; i<N-1 ;i ++){
            string s1= dict[i];
            string s2 = dict[i+1];
            int i1=0,j1 =0;
            while(i1<s1.size() && j1 < s2.size()){
                if(s1[i1] == s2[j1]) {
                    i1++;
                    j1++;
                }
                else {
                    int node = s1[i1] - 'a';
                    adj[node].push_back(s2[j1] - 'a');
                    break;
                }
            }
            
        }
        
        vector<int> topo;
        topo = topoSort(adj,K);
        
        string ans = "";
        for(auto it : topo){
            ans += 'a' + it;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends