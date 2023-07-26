class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour < dist.size() - 1) return -1;
        int l = 0;
        int r = 1e7+1;
        int m;
        int ans = -1;
        while (l <= r) {
            m = (l + r) / 2;            
            if (check(dist, hour, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    bool check(vector<int>& dist, double hour, int speed) {
        double time = 0;
        int i = 0;
        while (time <= hour && i < dist.size() - 1) {
            double d = 1.0*dist[i];
            time += ceil(1.0*(d / speed));
            i++;
        }
                         
        // seperately for the last index
        double d = 1.0*dist[dist.size()-1];
        time += 1.0*(d/ speed);
        return (time <= hour);
    }
};