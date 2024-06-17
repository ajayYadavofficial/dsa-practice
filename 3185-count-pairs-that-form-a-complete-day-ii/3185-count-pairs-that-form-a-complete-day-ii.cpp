class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> remainderCount;
        long long ans = 0;
        
        for (int i = 0; i < hours.size(); ++i) {
            int remainder = hours[i] % 24;
            int complement = (24 - remainder) % 24;
            
            if (remainderCount.find(complement) != remainderCount.end()) {
                ans += remainderCount[complement];
            }
            
            remainderCount[remainder]++;
        }
        
        return ans;
    }
};