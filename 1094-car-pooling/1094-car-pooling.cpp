class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       
        map<int,int>m;
        for(int i=0;i<trips.size();i++){
            m[trips[i][1]]+=trips[i][0];
            m[trips[i][2]]-=trips[i][0];
        }
        int curr=0;
        for(auto it=m.begin();it!=m.end();it++){
            curr+=it->second;
            if(curr>capacity)return false;
        }
        return true;

    }
};