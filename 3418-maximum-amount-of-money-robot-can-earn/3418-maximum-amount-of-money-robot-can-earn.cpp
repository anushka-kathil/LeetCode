class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        
        for(int k = 0; k < 3; k++) {
            if(coins[0][0] >= 0) {
                dp[0][0][k] = coins[0][0];
            } else {
                dp[0][0][k] = coins[0][0];
                if(k > 0) dp[0][0][k] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;
                
                for(int k = 0; k < 3; k++) {
                    int best = INT_MIN;

                    if(i > 0 && dp[i-1][j][k] != INT_MIN)
                        best = max(best, dp[i-1][j][k]);

                    if(j > 0 && dp[i][j-1][k] != INT_MIN)
                        best = max(best, dp[i][j-1][k]);

                    if(best == INT_MIN) continue;

                    if(coins[i][j] >= 0) {
                        dp[i][j][k] = best + coins[i][j];
                    } else {
                        dp[i][j][k] = best + coins[i][j];

                        if(k > 0) {
                            int prev = INT_MIN;

                            if(i > 0)
                                prev = max(prev, dp[i-1][j][k-1]);
                            if(j > 0)
                                prev = max(prev, dp[i][j-1][k-1]);

                            if(prev != INT_MIN)
                                dp[i][j][k] = max(dp[i][j][k], prev);
                        }
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};