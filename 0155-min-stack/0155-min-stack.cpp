class MinStack {
public:
   stack<pair<int, int>> s; 
    int minVal;
    
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        if (s.size() == 0) {
            minVal = val;
        } else {
            minVal = s.top().second;
        }
        minVal = min(minVal, val);
        s.push({val, minVal});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */