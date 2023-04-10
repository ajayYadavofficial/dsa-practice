class Solution {
public:
    bool isValid(string s) {
        // Stack to keep track of pairs of parentheses
        stack<char> stack;
        int n = s.length();
        
        // Handling edge cases 
        if(n == 0) return true;
        if(n == 1) return false;
        
        for(int i = 0; i < n; i++) {    
            // Current number 
            int c = s[i];
        
            // If it is an opening bracket 
            if(c == '{' || c == '(' || c == '[') {
                // Add it to the stack 
                stack.push(c);
        
            } else if(c == '}' || c == ')' || c == ']') {
                if(stack.empty()) return false;
                // If brackets aren't closed in correct order - return false 
                if(c == '}' && stack.top() != '{') return false;
                
                else if(c == ']' && stack.top() != '[') return false;
          
                else if(c == ')' && stack.top() != '(') return false;
                
                else {   
                    // If all conditions are satisifed - pop an element off the stack
                    stack.pop();
                }
            }
        }
        // If our logic has evaluated to true, and all the elements have been popped off 1 by 1 - then the stack is empty 
        // and our solution 'true' - else it is false.
        return stack.empty();
        
    }
};