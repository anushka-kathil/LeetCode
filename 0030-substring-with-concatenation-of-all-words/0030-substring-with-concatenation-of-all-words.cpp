class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        if(s.empty() || words.empty()) return v;
        
        int wordLen = words[0].size();
        int wordCount = words.size();
        int len = wordLen * wordCount;

        if(s.size() < len) return v;

        unordered_map<string,int> m;
        for(auto word:words) m[word]++;

        for(int i=0; i<wordLen; i++){
            int left=i, right=i, count=0;
            unordered_map<string,int> seen;
            while(right + wordLen <= s.size()){
               string ns=s.substr(right,wordLen);
               right+=wordLen;
               if(m.count(ns)){
                seen[ns]++;
                count++;
                while(seen[ns] > m[ns]){
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left+=wordLen;
                }

                if(count == wordCount) v.push_back(left);
               }

               else{
                seen.clear();
                count=0;
                left=right;
               }
            }
        }

          return v;
    }
};