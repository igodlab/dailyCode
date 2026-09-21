class MinStack {
private: 
    stack<int> stck;
    stack<int> auxStck;

public:
    MinStack() {
    }
    
    void push(int val) {
        stck.push(val);
        // store min value logic so that getMin() can run in O(1)
        if (!auxStck.empty()) {
            val = min(val, auxStck.top());
        }
        auxStck.push(val);
    }
    
    void pop() {
        stck.pop();
        auxStck.pop();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return auxStck.top();
    }
};
