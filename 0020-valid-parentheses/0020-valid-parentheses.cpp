class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(st.empty() == true) st.push(s[i]);
            else if(st.top() == '(' && s[i] == ')' || st.top()=='{' && s[i] == '}' || st.top()=='[' && s[i] == ']')
            { st.pop();}
            else
            st.push(s[i]);     
        }

        if(st.empty() == true) return true;
        return false;
    }
};