class Solution {
public:
    

    
    string longestPalindrome(string s) {
        
          int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        pair<int,int> max;
		//If length of interval is 1, ie len =0, its a palindrome by defaultt
		//If len -1, then if both elements are same, then palindrome
		//If len > 1 and len < n We have, if substring is palindrome and edge elements are same, then palindrome.
        for(int len  = 0; len < n; len++)
        {
            for(int i =0, j = len; j < n ;i++,j++)
            {
                if(len==0)
                {
                    dp[i][j] = 1;
                    max ={i,j};
                }
                else if(len==1 && s[i]==s[j])
                {
                    dp[i][j] = 1;
                    max = {i,j};
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j] = 1; 
                    max = {i,j};
                }
            }
        }
		// Latest stored value will be max since we are going in order of intervals
        return s.substr(max.first,(max.second-max.first+1));
    }
};