class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
    
        sort(rectangles.begin(),rectangles.end());
        unordered_map<int,vector<int>> mp;
        for(auto& r:rectangles)
        {
            mp[r[1]].push_back(r[0]);
        }
        vector<int> v;
        vector<int> res;
        for(auto& p:points)
        {
            int a=p[0],b=p[1];
            int cnt=0;
            for(int i=b;i<=100;i++)
            {
                v=mp[i];
                int t=lower_bound(v.begin(),v.end(),a)-v.begin();
                cnt+=(v.size()-t);
            }
            res.push_back(cnt);
        }
        return res;
    }
};