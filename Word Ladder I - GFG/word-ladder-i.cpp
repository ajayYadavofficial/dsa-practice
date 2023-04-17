//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        queue<pair<string, int>> q;
        q.push({startWord,1});
        while(!q.empty()){
            string st = q.front().first;
            int level = q.front().second;
            q.pop();
            if( st == targetWord) return level;
            else{
                for( int i=0;i<st.size();i++){
                    string temp = st;
                    for( int j=0; j<26; j++){
                        char ch = 'a' + j;
                        temp[i] = ch;
                        auto it = find(wordList.begin(), wordList.end(), temp);
                        if(it != wordList.end()){
                            q.push({temp,level+1});
                            // remove from the list
                            // cout<<temp<<endl;
                            wordList.erase(it);
                        }
                    }
                }
                
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends