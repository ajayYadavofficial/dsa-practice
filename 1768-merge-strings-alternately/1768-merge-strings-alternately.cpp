class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int i=0,j=0;
        string ans = "";
        bool flag = 1;
        while( i < word1.size() && j < word2.size()){
            if(flag){
             ans += word1[i];
            i++; flag  = false;}
            else{
                ans += word2[j];
                j++; flag = true;
            }
            // flag = ~flag;
        }
        while( i < word1.size()){
            ans += word1[i];
            i++;
        }
        while( j < word2.size()){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};