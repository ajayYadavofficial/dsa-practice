class Solution {
public:
    int modPow(long long x, long long y, int m)
{
    if (y == 0)
        return 1;
    long long p = modPow(x, y / 2, m);
    p = (p * p) % m;
    return y % 2 ? (p * (x % m)) % m : p;
}
int minNonZeroProduct(int p) {
    long long cnt = (1ll << p) - 1, mod = 1000000007;
    return cnt % mod * modPow(cnt - 1, cnt / 2, mod) % mod;
}
};