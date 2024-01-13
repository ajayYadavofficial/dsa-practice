class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arr1 (26, 0);
        vector<int> arr2 (26, 0);
        
        for(int i = 0; i< s.size(); i++){
            arr1[s[i] - 'a']++;
            arr2[t[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i< 26; i++){
            ans += abs(arr2[i] - arr1[i]);
        }
        
        return ans/2;
    }
};