// class Solution {
// public:
//     string removeStars(string s) {
//         stack<char> st;

//         for(int i=0;i<s.size();i++){
//             char cur = s[i];
//             if(cur == '*'){
//                 st.pop();
//             }else{
//                 st.push(cur);
//             }
//         }
//         string ans = "";
//         while(!st.empty()){
//             ans = st.top() + ans;
//             st.pop();
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '*') ans.pop_back();
            else ans+=s[i];
        }
        return ans;
    }
};