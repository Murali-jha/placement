class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        size--;
        while(size--){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int size = q.size();
        size--;
        while(size--){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int ans = q.front();
        q.pop();
        q.push(ans);
        return ans;
    }
    
    bool empty() {
        if(q.size()==0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
