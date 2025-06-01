class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
       
        int s = st.size();

        for(int i=0; i<s; i++){
            st2.push(st.top());
            st.pop();
        }

         st.push(x);

          while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    

    }
    
    int pop() {
        int t = st.top();
        st.pop();
        return t;
        
    }
    
    int peek() {
        return st.top();
        
    }
    
    bool empty() {
        return st.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */