class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<unordered_set<int>> seen;
        int sz=-1;
        for(int n:nums){
            bool add=false;
            int i=0;
            for(auto& vec:ans){
                if(vec.size()==0 || seen[i].count(n)==0){ // if the element is not present in current row
                    vec.push_back(n);
                    seen[i].insert(n);
                    add=true;
                    break;
                }
                ++i;
            }
            if(!add){ // if it is present in the current 2-D array, create new row and add it  
                ans.push_back({n});
                seen.push_back({n});
                sz++;
            }
        }
        return ans;
    }
};