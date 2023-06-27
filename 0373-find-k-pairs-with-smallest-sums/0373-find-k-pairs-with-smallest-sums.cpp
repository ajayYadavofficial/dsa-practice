class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair< int, pair<int,int> >> pq;
        vector<vector<int>> ans;
        
        for(int i=0; i<nums1.size();i++){
            for(int j=0; j<nums2.size() ; j++){
                int a = nums1[i];
                int b = nums2[j];
                if(pq.size() < k)pq.push({ a+b, {a,b}});
                else if( a + b < pq.top().first){
                    pq.pop();
                    pq.push({ a+b, {a,b}});
                }
                else break;
            }
        }
        cout<<pq.size();
        while(!pq.empty()){
            auto it = pq.top();
            int a = it.second.first;
            int b = it.second.second;
            ans.push_back({a,b});
            // cout<<"sum = "<<sum<<" a = "<<a<<"  b = "<<b<<endl;
            pq.pop();
        }
        return ans;
    }
};

