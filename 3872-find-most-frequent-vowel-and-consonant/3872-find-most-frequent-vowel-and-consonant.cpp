class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int max_vowel = 0, max_consonant = 0;

        auto isVowel = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (freq[i] == 0) continue;

            if (isVowel(c)) {
                max_vowel = max(max_vowel, freq[i]);
            } else {
                max_consonant = max(max_consonant, freq[i]);
            }
        }

        return max_vowel + max_consonant;
    }
};
