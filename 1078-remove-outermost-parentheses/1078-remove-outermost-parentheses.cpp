class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int n = s.size();
        string ans="";
        for(int i=0; i<n-1; i++){
            if(s[i] == '(' && open==0){
                open++;
            }
            else if(s[i] == '('){
              open++;
              ans+=s[i];
            }
            else if(s[i] == ')' && open >1){
                open--;
                ans+=s[i];
            }
            else{
                open--;
            }

        }
        return ans;
        
        
    }
};