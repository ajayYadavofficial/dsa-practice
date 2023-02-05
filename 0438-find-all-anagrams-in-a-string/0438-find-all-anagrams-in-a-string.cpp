class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> base(26,0);
        for(int i=0; i<p.size();i++){
            base[p[i]-'a']++;
        }
        
        int i=0, j = 0;
        vector<int> ans;
        while( i <= j && j<s.size()){
            
            if( j - i +1 == p.size()){
                vector<int> current(26,0);
                // loop from i to j to check for in base array
                // cout<<i<<" "<<j<<endl;
                for(int k = i ; k<= j;k++){
                    current[ s[k] - 'a' ]++;
                }
                bool isSame = true;
                for(int k =0; k<26; k++){
                    if(base[k] == current[k]){
                        continue;
                    }else{
                        isSame = false;
                        break;
                    }
                    
                }
                
                if(isSame) ans.push_back(i);
                i++;
                
            }
            j++;
        }
        return ans;
    }
};