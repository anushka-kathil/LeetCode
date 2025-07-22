class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length() || s.empty() || t.empty()) return "";
        if(s==t) return s;
        unordered_map<char,int> need, window;

        for(auto ch:t) need[ch]++;

        int left=0,right=0,valid=0, minLen=INT_MAX;
        int start=0;

        while(right < s.size()){
            // window[s[right]]++;
            // right++;
            
        char c = s[right];
       
         if (need.count(c)) {
            window[s[right]]++;
           if (window[s[right]] == need[s[right]])
              valid++;
            }
             right++;

            while(valid == need.size()){
                if(right - left < minLen){ 
                    minLen = right - left;
                    start = left;
                }
                
              char d = s[left];
              left++;
               if (need.count(d)) {
               if (window[d] == need[d]) valid--;
               window[d]--;
              }

            }
        }

       if(minLen == INT_MAX) return "";
       
       return s.substr(start,minLen);
    }
};