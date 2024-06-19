class Solution {
public:
    bool isPossible(int mid, vector<int>& bloomDay, int m, int k) {
        int count = 0;  // to count the number of adjacent flowers that have bloomed
        int bouquets = 0;  // to count the number of bouquets we can make

        for (int day : bloomDay) {
            if (day <= mid) {
                count++;  // flower has bloomed
                if (count == k) {
                    bouquets++;
                    count = 0;  // reset count after making a bouquet
                }
            } else {
                count = 0;  // reset count if flower has not bloomed
            }
            if (bouquets >= m) return true;  // if we have enough bouquets
        }
        return false;  // not enough bouquets
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (static_cast<long long>(m) * k > n) return -1;

        // binary search on answer, can k become zero in SOME D days
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + ((r - l) / 2);
            if (isPossible(mid, bloomDay, m, k)) {
                ans = min(ans, mid);
                r = mid - 1;  // search on the left
            } else {
                l = mid + 1;  // search on the right
            }
        }
        return ans;
    }
};
