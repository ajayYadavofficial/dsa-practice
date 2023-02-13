class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target = sum/2;  //our target sum should be close to half of original because
		                    //this is the best possible case when ans = 0.
        vector<vector<int>>left = get_subset_sum(nums,0,n/2-1); //this returns all possible sums if select i elements from left part
        vector<vector<int>>right = get_subset_sum(nums,n/2,n-1);
        int ans=INT_MAX;
        for(int i=0;i<=n/2;i++){
            sort(right[n/2-i].begin(),right[n/2-i].end());
            for(int j=0;j<left[i].size();j++){
               int curr_left = left[i][j];
               auto it = lower_bound(right[n/2-i].begin(),right[n/2-i].end(),target-curr_left);//we do binary search in the right part such that we choose n/2-i elements (i.e. total n/2) which is closest to target i.e. sum/2.
                if(it!=right[n/2-i].end())
               ans=min(ans,abs(sum-2*(curr_left + *it)));
            }
        }
        return ans;
    }
    
    vector<vector<int>> get_subset_sum(vector<int>nums,int l,int r){
       

        int len=r-l+1;
        vector<vector<int>>res(len+1,vector<int>());
        for(int i=0;i<(1<<len);i++){
              int sum=0,cnt=0;
            for(int j=0;j<len;j++){
                if(i & (1<<j)){
                    sum+=nums[l+j];
                    cnt++;
                }
            }
            res[cnt].push_back(sum);
        }
        return res;
    }
};