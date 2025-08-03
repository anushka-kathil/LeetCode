class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> ms;
        unordered_map<char,int> mt;
         for(int i=0; i<s.size(); i++){
            ms[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            mt[t[i]]++;
            // if(ms[t[i]] == 0) return t[i];
        }
         for(int i=0; i<t.size(); i++){
            if(ms[t[i]] == 0 || mt[t[i]] > ms[t[i]]) return t[i];
         }

        return ' ';

        
    }
};