class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26) return false;
        vector<int>a(26,0);
        for(char i : sentence){
             a[i-'a'] = 1;
        }
        for (auto i : a){
            if(i != 1) return false;
        }
        return true;
    }
};