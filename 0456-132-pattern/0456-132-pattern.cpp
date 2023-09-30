// class Solution {
// public:
        
//     bool find132pattern(vector<int>& nums) {
//         stack<int> st;
        
//         for(int i = 0; i< nums.size(); i++){
            
//             if(st.empty() || st.top() < nums[i]){
//                 st.push(nums[i]);
//             }
//             if(st.size() >= 2 && nums[i] < st.top()){
//                 return true;
//             }
            
//         }
//         return false;
        
//     }
// };


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return 0;
        vector<int> n_k;//keep track of the nums[k]
        vector<int> n_i(n);
        n_i[0]=nums[0];
        for(int i=1; i<n; i++)
            n_i[i]=min(n_i[i-1], nums[i]);
        for(int j=n-1; j>0; j--){
            if (nums[j]<=n_i[j]) continue;
            while(!n_k.empty()&& n_k.back()<=n_i[j]) 
                n_k.pop_back();
            if(!n_k.empty() && n_k.back()<nums[j]) 
                return 1;
            n_k.push_back(nums[j]);
        }
        return 0;
    }
};
