class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        int i=0, j = 0, n = nums.size();
//         while(i <= j && j<n && i<n){
//             if(nums[i] != 0){
//                 i++;
//                 j++;
//             }
//             else if(nums[i] == 0){
                
//                 while(nums[j] == 0 && j<n){
//                     j++;
//                 }
//                 // cout<<i<<" i "<<j<<" j"<<endl;
//                 int x = j-i;
//                 cnt += (x*(x+1))/2;
//                 i=j;
//             }
//         }
        
        for(i=0; i<n;i++){
            if(nums[i] != 0) continue;
            else if (nums[i] == 0){
                for(j=i; j<n; j++){
                    if(nums[j] != 0) break;
                }
                // cout<<i<<" i "<<j<<" j"<<endl;
                long long x = j-i;
                cnt += (x*(x+1))/2;
                i = j;
            }
        }
        
       return cnt;
    }
};