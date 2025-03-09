class Solution {
public:
    string findValidPair(string s) {
        int n=s.length();
        unordered_map<int,int> m;
        string ans="";
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        for(int i=0;i<n-1;i++){
            int x= s[i]-'0';
            int y= s[i+1]-'0';
            if(s[i]!=s[i+1] && x == m[s[i]] &&  y == m[s[i+1]]){
                ans+=s[i];
                ans+=s[i+1];
                break;
            }
        }
        return ans;
        
    }
};