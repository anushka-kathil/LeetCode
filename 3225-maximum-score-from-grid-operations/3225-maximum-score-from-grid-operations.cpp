#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                pref[j][i + 1] = pref[j][i] + (long long)grid[i][j];
            }
        }

        const long long INF = 1e17;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));
        
        for (int h = 0; h <= n; ++h) {
            dp[0][h] = 0;
        }

        for (int j = 0; j < n; ++j) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -INF));
            for (int h2 = 0; h2 <= n; ++h2) {
                vector<long long> suf_A(n + 1, -INF);
                for (int h1 = 0; h1 <= n; ++h1) {
                    long long score = max(0LL, pref[j][h1] - pref[j][h2]);
                    suf_A[h1] = dp[h1][h2] + score;
                }
                for (int h1 = n - 1; h1 >= 0; --h1) {
                    suf_A[h1] = max(suf_A[h1], suf_A[h1 + 1]);
                }
                
                long long pref_max_dp = -INF;
                for (int h3 = 0; h3 <= n; ++h3) {
                    long long score = max(0LL, pref[j][h3] - pref[j][h2]);
                    long long opt1 = suf_A[h3];
                    long long opt2 = (pref_max_dp == -INF) ? -INF : pref_max_dp + score;
                    next_dp[h2][h3] = max(opt1, opt2);
                    pref_max_dp = max(pref_max_dp, dp[h3][h2]);
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        for (int h = 0; h <= n; ++h) {
            ans = max(ans, dp[h][0]);
        }
        return ans;
    }
};