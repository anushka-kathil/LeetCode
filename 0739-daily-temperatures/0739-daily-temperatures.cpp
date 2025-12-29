class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> v(n,0);
        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int ind = st.top();
                st.pop();
                v[ind] = i-ind;
            }
            st.push(i);  
        }
        return v;
        
    }
};