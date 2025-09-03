class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();
        for(int i=0; i<n; i++){
            if(expression[i] == '(' || expression[i] == ',') continue;
            else if(expression[i] == 't' || expression[i] == 'f' || expression[i] == '&' || expression[i] == '|' || expression[i] == '!'){
                st.push(expression[i]);
            }
            else if(expression[i] == ')'){
                bool tr = false, fl = false;
                while(st.top()!='!' && st.top()!='&' && st.top()!='|'){
                    char top = st.top();
                    st.pop();
                    if(top == 't') tr = true;
                    else fl = true;
                }
                char op = st.top();
                st.pop();
                if(op == '!'){
                    st.push(tr?'f':'t');
                }
                else if(op == '&'){
                    st.push(fl?'f':'t');
                }
                else{
                    st.push(tr?'t':'f');
                }
            }
        }


        return st.top() == 't';

        
    }
};