class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
       unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        
        long long min = 1;
        
        while( min < INT_MAX){
            if( !mp[min] ) return min;
            min *= 2;
        }
        return 0;
    }
};