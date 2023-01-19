class Solution {
public:
    
int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> count(k,0);
    int n = nums.size();
    
    for(int i=1; i<n;i++){
        nums[i] = nums[i-1]+nums[i]; 
    }
    for(int i=0; i<n;i++){
        nums[i] = (nums[i]%k + k) % k; // it is done is the sum is -ve then the modulo shoul dcome in the range of 0 to n-1
        count[nums[i]] ++;
    }
    
    int result = count[0];
    for(int x : count){
        
        result += (x*(x-1))/2;
        
    }
    
    return result;
        
        
        
        
    }
};