class MinStack {
    stack <long long int> st;
    long long mini=INT_MAX;
public:
    MinStack() {
         
    }
    
    void push(int val) {
       if(st.empty()){
        st.push(val);
        mini=val;
       }

       else if(val>=mini)
       st.push(val);

       else
        {
            st.push(2LL*val - mini);
            mini=val;
        }
    }
    
    void pop() {
    //     if(st.empty())
    //     return;
    //    long long int n= st.top();
    //      st.pop();

        if(st.top()<mini)
        mini = 2LL*mini - st.top();

        st.pop();
       
    }
    
    int top() {
       if(mini < st.top())
       return st.top();
       else
       return mini;
        
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