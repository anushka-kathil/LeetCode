class MinStack {
public:
    stack<int> st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(val < mini)
        mini = val;
    }
    
    void pop() {
        if(st.top()==mini){
        mini = INT_MAX;
        st.pop();
        stack<int> st2 = st;
        // cout<<st2.top();
        while(!st2.empty()){
            cout<<st2.top()<<endl;;
            if(st2.top() < mini){
                mini = st2.top();
            }
            st2.pop();
        }
        }
        else
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;    
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