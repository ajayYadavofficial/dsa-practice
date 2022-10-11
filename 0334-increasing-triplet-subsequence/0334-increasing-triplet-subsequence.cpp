class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first=INT_MAX,second=INT_MAX; //set max value
    
	//scracth value from vector
    for(auto &el:nums){
        if(el<=first){
            first=el; //set first as el
        }else if(el<=second){ //when element greater than first element
            second=el; //set second as el
        }else{ //here come when two element 3rd element is greater than first and second ..so it is true
            return true; //return the result
        }
    }
    
	//return as false
    return false;
    }
    
};