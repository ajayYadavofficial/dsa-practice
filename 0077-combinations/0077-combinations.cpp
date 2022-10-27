class Solution {
public:
    void f(int ind, int n,vector<int> &smallAns, int K, vector<vector<int>> &ans){
        if(K > n -ind +1) return;
         if( K == 0){
                ans.push_back(smallAns);
             return;
            }
        if(ind > n){
            return;
        }
        
        // take
        smallAns.push_back(ind);
        f(ind+1, n,smallAns, K-1, ans);
        smallAns.pop_back();
        //Not take
        f(ind+1,n,smallAns,K, ans);
        return;
        
    }
    vector<vector<int>> combine(int n, int k) {
      
        vector<int> smallAns;
        vector<vector<int>> ans;
        f(1,n,smallAns,k,ans);
        return ans;
    }
};