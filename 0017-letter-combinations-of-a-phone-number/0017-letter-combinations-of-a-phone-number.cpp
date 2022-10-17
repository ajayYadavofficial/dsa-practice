class Solution {
public:
    vector<string> ans;
    void combinations(string digits, string currString, vector<string> numbers, int start, int end){
        if(start == end)ans.push_back(currString);
        else{
            int index = digits[start]-'0';
            for(int i=0; i<numbers[index].length(); i++)
                combinations(digits, currString+numbers[index][i], numbers, start+1, end);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return ans;
        vector<string> numbers = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combinations(digits,"", numbers, 0, digits.length());
        return ans;
    }
};