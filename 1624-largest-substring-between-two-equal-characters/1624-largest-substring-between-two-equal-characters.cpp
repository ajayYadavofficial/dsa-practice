// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         map<char, vector<int>> mp;
//         int maxi = INT_MIN;
//         for(int i = 0; i< s.size(); i++){
//             mp[s[i]].push_back(i);
//             maxi = max( mp[s[i]][mp[s[i]].size()-1]- mp[s[i]][0], maxi  );
//         }
        
//         if(maxi == 0) return -1;
//         return maxi-1;
//     }
// };

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (s[left] == s[right]) {
                    ans = max(ans, right - left - 1);
                }
            }
        }
        
        return ans;
    }
};