class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive, devoweled;

        auto devowel = [&](string w) {
            for (char &c : w) {
                if (isVowel(c)) c = '*';
                else c = tolower(c);
            }
            return w;
        };

        for (string word : wordlist) {
            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = word;
            string dv = devowel(lower);
            if (!devoweled.count(dv))
                devoweled[dv] = word;
        }
        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string dv = devowel(lower);
            if (devoweled.count(dv)) {
                ans.push_back(devoweled[dv]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
