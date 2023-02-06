// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> ans;
//         int i = 0, j = n;
//         while( i < n && j < 2*n){
//             cout<<i<<" "<<j<<endl;
//             ans.push_back(nums[i]);
//             ans.push_back(nums[j]);
//             i++;
//             j++;
            
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for(int i=0,j=nums.size()/2;i<nums.size()/2,j<nums.size();i++,j++) {
            res.push_back(nums[i]);
            res.push_back(nums[j]);

        }
        return res;
    }
};