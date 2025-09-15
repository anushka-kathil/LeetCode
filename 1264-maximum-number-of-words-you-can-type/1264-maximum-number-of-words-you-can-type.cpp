class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenKeys(brokenLetters.begin(), brokenLetters.end());
        int wordCount = 0;
        bool canType = true;

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (canType) wordCount++;
                canType = true;
            } else if (brokenKeys.count(text[i])) {
                canType = false;
            }
        }
        return wordCount;
    }
};
