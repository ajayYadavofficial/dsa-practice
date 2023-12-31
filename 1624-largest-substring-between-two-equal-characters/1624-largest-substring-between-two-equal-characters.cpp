class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, vector<int>> mp;
        int maxi = INT_MIN;
        for(int i = 0; i< s.size(); i++){
            
            mp[s[i]].push_back(i);
            // cout<<mp[s[i]][0];
            maxi = max( mp[s[i]][mp[s[i]].size()-1]- mp[s[i]][0], maxi  );
            
        }
        
        if(maxi == 0) return -1;
        return maxi-1;
    }
};