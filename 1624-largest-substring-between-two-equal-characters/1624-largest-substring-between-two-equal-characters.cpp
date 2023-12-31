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
    int last[26] = {0}, ans = -1;
    for(int i = 0; i < s.size(); ++i) last[s[i] - 'a'] = i;
    for(int i = 0; i < s.size(); ++i) ans = max(ans, last[s[i] - 'a'] - i - 1);
    return ans;
}
};