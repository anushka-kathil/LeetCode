class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(string& s: strs){
            string key=s;
            sort(s.begin(),s.end());
            m[s].push_back(key);
        }
        vector<vector<string>> result;
        for(auto& i: m){
            result.push_back(i.second);
        }
        return result;
    }
};