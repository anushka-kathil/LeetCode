class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0, open=0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i]==')'){
                ans=max(ans,open);
                if(open>0)
                open--;
            }
        }
        return ans;
    }
};