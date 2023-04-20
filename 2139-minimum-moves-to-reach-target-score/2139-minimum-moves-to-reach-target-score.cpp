class Solution {
public:
    int minMoves(int target, int maxDoubles) {
    int res = 0;
    while (target && maxDoubles) {
        if (target % 2)
            --target;
        else {
            --maxDoubles;
            target /= 2;
        }
        ++res;
    }
    return res + target - 1;
}
};