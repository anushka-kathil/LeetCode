class Solution {
public:
    int dist(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();

        int total = 0;
        for (int i = 1; i < n; i++) {
            total += dist(word[i] - 'A', word[i - 1] - 'A');
        }

       
        vector<int> dp(26, 0);

        for (int i = 1; i < n; i++) {
            int prev = word[i - 1] - 'A';
            int curr = word[i] - 'A';

            vector<int> new_dp = dp;

            for (int j = 0; j < 26; j++) {
                
                int gain = dist(prev, curr) - dist(j, curr);
                new_dp[prev] = max(new_dp[prev], dp[j] + gain);
            }

            dp = new_dp;
        }

        int maxSave = 0;
        for (int x : dp) maxSave = max(maxSave, x);

        return total - maxSave;
    }
};