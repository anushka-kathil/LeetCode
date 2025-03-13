class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.length();
        int n2=t.length();

        if(n1!=n2)
        return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(int i=0;i<n1;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }

        for(int i=0;i<n1;i++){
            if(m1[s[i]] != m2[s[i]]){
                return false;
            }
           
        }

        return true; 
    }
};