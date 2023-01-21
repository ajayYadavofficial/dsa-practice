class Solution {
public:
    
    long long find_cost(vector<int>& nums, vector<int>& cost, int ele)
    {
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            long long a = abs(nums[i] - ele);
            ans = ans + (a * cost[i]);
        }
            
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int minele = INT_MAX, mxele = INT_MIN;
        for(auto i:nums)
        {
            minele = min(minele, i);
            mxele = max(mxele, i);
        }
        long long ans = LLONG_MAX;
        while(minele <= mxele)
        {
            int mid = minele + (mxele - minele) / 2;
            long long temp = find_cost(nums, cost, mid);
            ans = min(ans, temp);
            long long r = find_cost(nums, cost, mid+1);
            long long l = find_cost(nums, cost, mid-1);
            // If mid is less than both it's immediate neighbours than it is the answer.
            if(temp < l && temp < r)
                return ans;
			// Shifting mid corresponding to the smallest possible answer.
            else if(temp < l && temp > r) // 
                minele = mid+1;
            else
                mxele = mid-1;
            
        }
        return ans;
    }
};