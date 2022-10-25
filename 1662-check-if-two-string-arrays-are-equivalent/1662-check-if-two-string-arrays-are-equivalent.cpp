class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0,w1=0,w2 = 0;
        while( i < word1.size() && j < word2.size()){
            cout<<word1[i][w1];
            if(word1[i][w1] != word2[j][w2] )
                {return false;}
            w1++;
            w2++;
            if(w1 == word1[i].size()){
                w1 = 0;
                i++;
            }
            if(w2 == word2[j].size()){
                w2 = 0;
                j++;
            }
            
        }
        return i == word1.size() && j == word2.size();
        
        
    }
};

