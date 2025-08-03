class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> mp;
        unordered_map<string, int> ms;
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                word += s[i];
            else {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        if (words.size() != pattern.length()) {

            return false;
        }

        for (int i = 0; i < pattern.length(); i++) {
            if (mp.find(pattern[i]) == mp.end())
                mp[pattern[i]] = i;

            if (ms.find(words[i]) == ms.end())
                ms[words[i]] = i;

            if (mp[pattern[i]] != ms[words[i]])
                return false;
        }
        return true;
    }
};