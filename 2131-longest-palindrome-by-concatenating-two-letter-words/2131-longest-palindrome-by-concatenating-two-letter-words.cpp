class Solution 
{
public:
    int longestPalindrome(vector<string>& words) 
    {
        int pp = 0, p = 0;
        
        unordered_map<string, int> freq;       
        for (string w : words) ++freq[w];
        
        for (auto&[w,f] : freq)
        {
            if (w[0] == w[1])
                p = max(p, f % 2), pp += f/2 * 2;
            else 
            {
                string ww = w; 
                swap(ww[0], ww[1]);
                if (freq.count(ww)) pp += min(f, freq[ww]);
            }
        }
        
        return (pp + p) * 2;
    }
};