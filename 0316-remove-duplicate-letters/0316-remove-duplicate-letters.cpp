// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         stack <char> st;
//         int n = s.size();
    
//         vector<bool> isOccured (26, 0);
//         for (int i = 0; i<n; i++){
//             // cout<<s[i]<<endl;
//             if(isOccured[ s[i] - 'a'] == 0){
//                 // first time occured
//                 while( !st.empty() && s[i] > st.top()){
//                     isOccured[st.top() - 'a'] = 0;
//                     st.pop();
//                 }
                
//                 st.push(s[i]);
//                 isOccured[s[i] - 'a'] = 1;
//             } else{
//                 // check the top element 
//                 continue;
//             }
//         }
//         // vector<bool> isOccured1 (26, 0);
//         string res = "";
        
//         while(!st.empty()){
//             char c = st.top();
//             st.pop();
//             res.push_back(c);
//         }
//         return res;
//     }
// };


class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::stack<char> stack;
        std::unordered_set<char> seen;
        std::unordered_map<char, int> last_occ;
        for (int i = 0; i < s.size(); i++) {
            last_occ[s[i]] = i;
        }
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (seen.find(c) == seen.end()) {
                while (!stack.empty() && c < stack.top() && i < last_occ[stack.top()]) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(c);
                stack.push(c);
            }
        }
        
        std::string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};