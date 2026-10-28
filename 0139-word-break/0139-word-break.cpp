class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), mx = 0;
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        for (auto &w : wordDict)
            mx = max(mx, (int)w.size());

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - mx); j < i; j++) {
                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};