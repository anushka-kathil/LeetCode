class Solution {
public:
    pair<int, int> expandFromCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1}; // Return valid palindrome range
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            auto [l1, r1] = expandFromCenter(s, i, i);     // Odd-length palindrome
            auto [l2, r2] = expandFromCenter(s, i, i + 1); // Even-length palindrome

            if (r1 - l1 + 1 > maxLen) {
                start = l1;
                maxLen = r1 - l1 + 1;
            }

            if (r2 - l2 + 1 > maxLen) {
                start = l2;
                maxLen = r2 - l2 + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
