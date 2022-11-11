class Solution {
public:
    
    int lastOccur(string s, char c, int first){
        int indx = -1;
        for(int i= s.size()-1; i>=first; i--){
            if(s[i] == c) {indx = i; break;}
        }
        return indx;
    }
    
    vector<int> partitionLabels(string s) {
        
        vector<int> partition;
        
        int i=0,j=-1,first=0,last=-1;
        while(i< s.size()){
            j = max(j,lastOccur(s,s[i],i));
            
            if(i==j){
                last = j;
                partition.push_back(last-first+1);
                first = last+1;
            }
            i++;
        }
        return partition;
    }
};