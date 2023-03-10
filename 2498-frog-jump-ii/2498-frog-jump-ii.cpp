class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res=stones[1]-stones[0]; // for size 2
        for(int i=0; i<stones.size()-2; i++)
            res=max(res, stones[i+2]-stones[i]);
        return res;
    }
};