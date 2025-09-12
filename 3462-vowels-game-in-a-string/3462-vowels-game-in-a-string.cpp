class Solution {
public:
    bool doesAliceWin(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        for (char c : s) if (isVowel(c)) return true;
        return false;
    }
};
