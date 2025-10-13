class Solution {
public:
    bool isAnagram(string s1, string s2){
        unordered_map<char,int> m1;
        if(s1.size()!=s2.size()) return false;
        for(int i=0; i<s1.size(); i++){
            m1[s1[i]]++;
            m1[s2[i]]--;
        }
        for(auto x:m1){
            if(x.second!=0) return false;
        }
        return true;
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