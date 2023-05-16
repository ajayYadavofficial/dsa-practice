class Solution {
public:
    // recursion
    
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0) return 0;
        if(num1 == num2) return 1;
        int left = 0, right = 0;
        if(num1 >= num2) left = 1 + countOperations(num1-num2, num2);
        else right = 1 + countOperations(num1, num2-num1);
            
        return left + right;
    }
};