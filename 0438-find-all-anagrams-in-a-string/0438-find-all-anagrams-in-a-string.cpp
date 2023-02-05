class Solution {
public:
    
    
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        if(s.size() < p.size()) return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<p_len;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-p_len+1);
        }
        return ans;
    }
};
    // vector<int> findAnagrams(string s, string p) {
//        vector<int> base(26,0);
//         for(int i=0; i<p.size();i++){
//             base[p[i]-'a']++;
//         }
        
//         int i=0, j = 0;
//         vector<int> ans;
//         while( i <= j && j<s.size()){
            
//             if( j - i +1 == p.size()){
//                 vector<int> current(26,0);
//                 for(int k = i ; k<= j;k++){
//                     current[ s[k] - 'a' ]++;
//                 }
//                 bool isSame = true;
//                 for(int k =0; k<26; k++){
//                     if(base[k] == current[k]){
//                         continue;
//                     }else{
//                         isSame = false;
//                         break;
//                     }
                    
//                 }
                
//                 if(isSame) ans.push_back(i);
//                 i++;
                
//             }
//             j++;
//         }
//         return ans;
//     }
// };




