class Solution {
public:
     int xorAllNums(vector<int>& A, vector<int>& B) {
        int x = 0, y = 0;
        for (int a : A)
            x ^= a;
        for (int b : B)
            y ^= b;
        return (A.size() % 2 * y) ^ (B.size() % 2 * x);
    }
};