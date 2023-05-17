class Solution {
public:
    long long minimumRemoval(vector<int>& A) {
        long N = A.size(), ans = LLONG_MAX, sum = accumulate(begin(A), end(A), 0L);
        sort(begin(A), end(A));
        for (int i = 0; i < N; ++i) ans = min(ans, sum - (N - i) * A[i]);
        return ans;
    }
};