class Solution {
public:
    
    int solve(int ind, int k, vector<int> &kids, vector<int>& cookies ){
        
        
        if(ind >= cookies.size()){
            // here we get a filled array of kids just return the max of them
            int maxi = INT_MIN;
            for(auto it : kids){
                maxi = max(maxi, it);
            }
            return maxi;
        }
        int ans = INT_MAX;
        for(int i = 0; i<k; i++){
            
            kids[i] += cookies[ind];
            ans = min(ans,solve(ind+1, k, kids, cookies) );
            
            // backtrack
            kids[i] -= cookies[ind];
            
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kids(k,0);
        return solve(0,k,kids,cookies);
    }
};