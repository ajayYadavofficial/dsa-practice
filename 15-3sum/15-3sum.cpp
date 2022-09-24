class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        if(n<3) return {};
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i< n-2; i++){
            if(i ==0 || nums[i] != nums[i-1]){
                int j= i+1, k=n-1;
                while(j<k){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum == 0){
                        ans.push_back({nums[i], nums[j],nums[k]});
                        while(j<k && nums[j] == nums[j+1]) j++;
                        while(j<k && nums[k] == nums[k-1]) k--;
                        j++; k--;
                    }
                    else if(sum >0){ 
                        k--;
                    }
                    else j++; // sum is less than zero then inc. j
                }
            }
        }
        
//         for (int i=0; i<n;i++){
//             int j = n-1;
//             int k =i+1, findSum = -nums[i];
//             if(nums[i] == 0) findSum = 0;
            
//             // cout<<i<<"Outside"<<endl;
//             vector<int> a;
//             while(k <= j && k != i && j != i){
//                 if(nums[k] + nums[j] == findSum){
//                     // cout<<nums[i]<<nums[j]<<nums[k]<<endl;
//                     a.push_back(nums[k]);
//                     a.push_back(nums[i]);
//                     a.push_back(nums[j]);
//                     ans.push_back(a);
//                     break;
//                 }
//                 if(nums[k] + nums[j] > findSum ){
//                     j--;
//                 }
//                 if(nums[k] + nums[j] < findSum ){
//                     k++;
//                 }
                
//             }
//             if(i >= 1 && nums[i-1] == nums[i] ){
//                 continue;
//             }
            
            
//         }
        return ans;
    }
};