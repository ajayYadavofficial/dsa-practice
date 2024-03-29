class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){ 
        int n = nums.size();
        if(n == 1) return {nums[0]};
        
        int freq = floor(n/3);
        cout<<freq<<endl;
        map<int,int> mp;
        for(auto it : nums) mp[it] ++;
        // vector<int> vec;
        nums.clear();
        for(auto it : mp){
            if(it.second > freq) nums.push_back(it.first);
        }
        return nums;
    }
};