class Solution {
public:
    int minOperations(string s) {
        int changes0 = 0; 
        int changes1 = 0; 
        
        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                if(s[i] != '0') changes0++;
                if(s[i] != '1') changes1++;
            }
            else {
                if(s[i] != '1') changes0++;
                if(s[i] != '0') changes1++;
            }
        }
        
        return min(changes0, changes1);
    }
};