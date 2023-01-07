// class Solution {
// public:
    
    
//     bool roundTrack(vector<int>& gas, vector<int>& cost, int st){
        
//         int n = gas.size();
//         // we move to next one step
//         int currTank = gas[st] - cost[st] + gas[(st+1)%n];
//         int indx = (st+1) %n;
        
//         while(indx != st){
            
//             if(currTank >= cost[indx]){
//                 currTank = gas[indx] - cost[indx] + gas[(indx+1)%n];
//                 indx = (indx+1)%n;
//             }
//             return false;
//         }
//         return true;
//     }
    
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
// //     finding start pt
        
//         for(int i=0; i<gas.size(); i++){
//             if(gas[i] >= cost[i]){
//                 // here I have strat indx
//                 int startIndx = i;
//                 // do check if we can reach this same indx again after a round track
                
//                 if( roundTrack(gas, cost, startIndx) ) return startIndx;
                
//             }
//         }
//         return -1;

//     }
// };

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            total_gas+=gas[i];
            total_cost+=cost[i];
            //for checking the total present gas at index i
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
               //there is a breakdown....so we will start from next point or index
                starting_point=i+1;
                //reset our fuel 
                curr_gas=0;
            }
        }
        return (total_gas<total_cost)?-1:starting_point;     
    }
};