class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        
        unordered_set<int> st;
        int num = 0;
        
        for (int i = 0; i < k; i++)
            num = (num << 1) + (s[i] - '0');
        
        st.insert(num);
        
        int mask = (1 << k) - 1;
        
        for (int i = k; i < s.size(); i++) {
            num = ((num << 1) & mask) + (s[i] - '0');
            st.insert(num);
        }
        
        return st.size() == (1 << k);
    }
};