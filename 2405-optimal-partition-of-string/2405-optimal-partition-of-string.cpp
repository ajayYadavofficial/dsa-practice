class Solution {
public:
    int partitionString(string s) {
        
        map <char,bool> mp;
        int count = 0;
        
        for(auto it : s){
            
            if(mp.find(it) != mp.end()){
                count++;
                mp.clear();
            }
            mp[it]= true;    
        }
        return count+1;
        
    }
};