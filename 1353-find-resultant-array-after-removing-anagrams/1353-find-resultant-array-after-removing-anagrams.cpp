class Solution {
public:
    bool isAnagram(string s1, string s2){
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        if(s1.size()!=s2.size()) return false;
        for(int i=0; i<s1.size(); i++){
            m1[s1[i]]++;
        }
        for(int i=0; i<s1.size(); i++){
            if(m1.find(s2[i]) != m1.end()) {
                m1[s2[i]]--;
            }
            if(m1[s2[i]] == 0) m1.erase(s2[i]);
        }
        if(m1.empty() == true) return true;
        else return false;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> v;
        v.push_back(words[0]);
        for(int i=1; i<n; i++){
             if(isAnagram(words[i],v.back()) == false){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};