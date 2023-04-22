class Solution {
public:
    
//     string solve(int ind,string num, int k,vector<vector<string>> &dp){
//         int n = num.size();
//         if( ind >= n) return "";
//         if( k == 0) return num.substr(ind); 
//         string pick = "", notPick = "";
//         if(dp[ind][k] != "-1") return dp[ind][k];
//         pick.push_back(num[ind]);
//         pick += solve(ind+1, num, k,dp);
        
//         notPick += solve(ind+1, num, k-1,dp);
        
//         return dp[ind][k] = min(pick, notPick);
        
//     }
    
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        int n = num.size();
        for( int i =0; i<n;i++){
            
            while( ( !st.empty()  && num[i] < st.top() )  && k >0){
                st.pop();
                k--;
            }
            if( (st.empty() && num[i] != '0') || !st.empty()){
                st.push(num[i]);
            }
        
        }
        
        string res = "";
        while( !st.empty()){
            char c = st.top();
            st.pop();
            res.push_back(c);
        }
        
        if(k > 0) {
            if(res.size() <= k) return "0";
            res = res.substr(k);
        }
        reverse(res.begin(), res.end());
        if(res.size() == 0) return "0";
        return res;
    }
};