class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        
        vector<int> nums;
        
        int i = 0, j = 0;
         
        // merging both the array into one
        while( i < n && j < m){
            
            if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
            
        }
        
        while( i < n){
            nums.push_back(nums1[i]);
            i++;
        }
        
        while( j < m){
            nums.push_back(nums2[j]);
            j++;
        }
        
        for (auto it : nums){
            cout<<it<<" ";
        }
        cout<<endl;
     
        double ans = 0.0;
        int ind = nums.size()/2;
        cout<<"index = "<<ind<<"\n";
        if(nums.size() % 2 == 0 ){
            ans = ( (1.0 * nums[ind-1]) + (1.0 * nums[ind]) ) / (1.0 * 2);
        }else{
            ans = ( (1.0 * nums[ind]) );
        }
        return ans;
    }
};