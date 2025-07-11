class MyStack {
    private:
    queue<int> q;
public:
    MyStack() {

        
    }
    
    void push(int x) {
        
        q.push(x);
        int size = q.size();
        for(int i = 0; i<size-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
        
    }
    
    int top() {
        return q.front();
        // q.pop();
        
    }
    
    bool empty() {
        if(q.empty()) return true;
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