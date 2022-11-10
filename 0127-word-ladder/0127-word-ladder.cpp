class Solution {
public:
   
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> Q;
        Q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        while(!Q.empty()){
            string word = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            
            if(word == endWord) return step;
            
            for(int i=0; i<word.size();i++){
                char org = word[i];
                for(char ch = 'a'; ch<='z' ; ch++){
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()){
                        // this means we find the word in set
                        Q.push({word,step +1});
                        st.erase(word);
                        
                    }
                    
                    
                }
                word[i] = org;
            }
            
        }
        return 0;
    }
};