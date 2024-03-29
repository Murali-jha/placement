class MinStack {
public:
    
    stack<int> s;
    stack<int> ss;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(ss.empty() || ss.top()>=val){
            ss.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(s.empty())
            return;
        if(s.top()==ss.top()){
            ss.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        
        return ss.top();
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
