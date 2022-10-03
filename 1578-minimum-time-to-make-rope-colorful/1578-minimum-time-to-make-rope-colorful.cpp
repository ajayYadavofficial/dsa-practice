class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, maxNumber = 0, currentSum = 0;
        
        char prev = '0';
        
        for(int i=0; i<colors.size(); i++)
        {
            if(prev == colors[i])
            {
                currentSum += neededTime[i];
                maxNumber = max(maxNumber, neededTime[i]);   
            }
            else
            {
                ans += currentSum - maxNumber;
                
                maxNumber =  neededTime[i];
                currentSum = neededTime[i];
            }
            
            prev = colors[i];
        }
        
        ans += currentSum - maxNumber;
        
        return ans;
    }
};