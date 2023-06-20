// class Solution {
// public:
//     vector<int> getAverages(vector<int>& nums, int k) {
//         int n = nums.size();
//         if( k > (n/2)){
//             //return vector of n size with -1 in it
//             vector<int> ans(n,-1);
//             return ans;
//         } 
//         vector<long long> preSum(n,0);
//         vector<int> ans(n,0);
//         for(int i = 0; i<n; i++){
//             if(i == 0)
//                 preSum[i] = nums[i];
//             else
//                 preSum[i] = preSum[i-1] + nums[i];
            
//             if( (i >=0 && i < k) || (i >= n-k && i < n) ) ans[i] = -1;
//         }
        
//         // for(auto it : ans) cout<<it<<" ";
//         // cout<<" upar ans hai "<<endl;
//         // for(auto it : preSum)cout<<it<<" ";
        
//         for(int i = k; i<n-k; i++){
//             int avg = preSum[i+k];
//             if( i-k > 0) avg -= preSum[i-k-1];
//             // cout<<"avg  = "<<avg<<endl;
//             ans[i] = (avg)/(2*k+1);
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

         int n=nums.size();
         vector<long long int> pre(n),suff(n);

         pre[0]=nums[0];
         for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        
 
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suff[i]=suff[i+1]+nums[i];
        
 
        vector<int> ans;

        for(int i=0;i<n;++i){

            if(i-k<0 || i+k>=n)
                ans.push_back(-1);
            
 
            else{

           long long int sum = (long long int)((suff[i-k]-suff[i]) + (pre[i+k]-pre[i]) + nums[i]);
                sum=sum/(2*k+1);
                ans.push_back(sum);
            }
        }
 
        return ans;
    }
};