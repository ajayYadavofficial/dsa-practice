class Solution 
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        int n = tasks.size(), i = 0;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({tasks[i][0], tasks[i][1], i});

        sort(v.begin(), v.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> ans;
        int endtime = v[i][0];

        while (i < n)
        {
            if (!pq.empty())
            {
                // do most prioritized task and update endtime of the task
                endtime += pq.top()[0];
                ans.push_back(pq.top()[1]);
                pq.pop();
            }
            while (i < n and v[i][0] <= endtime)
            {
                // push all the tasks which lies in the range [curTime, endtime]
                pq.push({v[i][1], v[i][2], v[i][0]});
                i++;
            }

            // if none of the task is in the range then take the next tasks
            if (i < n and endtime < v[i][0] and pq.empty())
                endtime = v[i][0];
        }
        
        // push remained task according to priority (already prioritized in pq)
        while (!pq.empty())
            ans.push_back(pq.top()[1]), pq.pop();

        return ans;
    }
};