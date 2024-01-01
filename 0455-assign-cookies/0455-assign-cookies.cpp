class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0)  return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int i = s.size() - 1;
        int j = g.size() - 1;
        while(i >= 0 && j >=0){
            if(s[i] >= g[j]){
                maxNum++;
                i--;
                j--;
            }
            else{
                j--;
            }
        }
        return maxNum;
    }
};