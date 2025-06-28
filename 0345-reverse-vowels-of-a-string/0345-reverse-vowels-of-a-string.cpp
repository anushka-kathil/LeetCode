class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int l=0, r=n-1;
        while(l<n && s[l] != 'a' && s[l] != 'A' && s[l] != 'e' && s[l] != 'E' && s[l]!='i' && s[l] != 'I' && s[l] != 'o' && s[l] != 'O' && s[l] != 'u' && s[l] != 'U')
        l++;
       while(r>=0 && s[r] != 'a' && s[r] != 'A' && s[r] != 'e' && s[r] != 'E' && s[r]!='i' && s[r] != 'I' && s[r] != 'o' && s[r] != 'O' && s[r] != 'u' && s[r] != 'U')
        r--;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
              while(l<n && s[l] != 'a' && s[l] != 'A' && s[l] != 'e' && s[l] != 'E' && s[l]!='i' && s[l] != 'I' && s[l] != 'o' && s[l] != 'O' && s[l] != 'u' && s[l] != 'U')
        l++;
                while(r>=0 && s[r] != 'a' && s[r] != 'A' && s[r] != 'e' && s[r] != 'E' && s[r]!='i' && s[r] != 'I' && s[r] != 'o' && s[r] != 'O' && s[r] != 'u' && s[r] != 'U')
        r--;
        }
        return s;
        
    }
};