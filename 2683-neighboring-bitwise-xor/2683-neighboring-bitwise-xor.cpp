class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        int start0 = 0;
        int start1 = 1;
        int exp0 = start0 ^ d[0];
        int exp1 = start1 ^ d[0];
        
        for(int i=1; i<n;i++){
            exp0 = exp0 ^ d[i];
            exp1 = exp1 ^ d[i];
        }
        
        if(exp0 == start0 || exp1 == start1) return true;
        return false;
    
    }

};