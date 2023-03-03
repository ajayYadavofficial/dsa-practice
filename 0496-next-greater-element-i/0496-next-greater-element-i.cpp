// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums2.size();
//         stack <int> s;
        
//         vector<int> sol(n);
        
//         for(int i =n-1; i >= 0; i-- ){
            
//             while( !s.empty() && s.top() <= nums2[i]){
//                 s.pop();
//             }
            
//             if(s.empty()){
//                 sol[i] = -1;
//             }else{
//                 sol[i] = s.top();
//                 s.push(nums2[i]);
//             }
            
//         }
        
//         for(int i=0; i< nums1.size(); i++){
//             int indx = lower_bound(sol.begin(), sol.end(), nums1[i]) - sol.begin();
//             cout<<indx<<" "<< sol[indx]<<endl;
//         }
        
//         return {};
        
//     }
// };


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> m; // hashmap of an num to its next greater number
        for(auto n: nums2){
            while(!stk.empty() && stk.top() < n){
                m[stk.top()] = n;
                stk.pop();
            }
            stk.push(n);
        }
        
        vector<int> ans;
        for(auto n: nums1)
            ans.push_back(m.count(n) ? m[n]: -1);        
        return ans;
    }
};