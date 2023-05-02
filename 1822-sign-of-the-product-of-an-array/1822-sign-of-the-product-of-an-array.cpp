class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt_negative = 0;
        for(auto it : nums){
            if(it < 0) cnt_negative++;
            if(it == 0) return 0;
        }
        if(cnt_negative %2 == 0) return 1;
        return -1;
    }
};