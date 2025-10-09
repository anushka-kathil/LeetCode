class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // if(s==1 && s[0]>) 
        unordered_map<char,int> m;
        int len = 0, c=0;
        for(int i=0; i<n; i++){
            int j = i,space=0;
            m.clear();
            while(m[s[j]]==0 && j<n){
                if(s[j] == ' ' && space==0){
                    space++; 
                    j++;
                    continue;
                }
                else if(s[j] == ' ') { break;}
                m[s[j]]++;
                j++;
            }
            // if(n!=1 && j==n){
            // j--;}
            len=max(len, j-i);
            
            // cout<<j<<" "<<i<<endl;
        }
        return len;  
    }
};