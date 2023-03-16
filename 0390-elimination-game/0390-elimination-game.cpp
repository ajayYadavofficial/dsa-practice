class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        if (n <= 4) return 2;
        if (n % 2 != 0) n -= 1;
        if (n % 4 != 0) return 4 * lastRemaining(n/4);
        return 4 * lastRemaining(n/4) - 2;
    }
};