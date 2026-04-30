class Solution {
public:
    int maxPathScore(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        vector dp(n, vector(m, vector<int>(k+1, -1)));

        int c = (g[0][0] == 0 ? 0 : 1);
        if(c <= k) dp[0][0][c] = g[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int x=0;x<=k;x++){
                    if(dp[i][j][x] == -1) continue;

                    if(i+1<n){
                        int nc = x + (g[i+1][j]==0?0:1);
                        if(nc<=k)
                            dp[i+1][j][nc] = max(dp[i+1][j][nc], dp[i][j][x] + g[i+1][j]);
                    }

                    if(j+1<m){
                        int nc = x + (g[i][j+1]==0?0:1);
                        if(nc<=k)
                            dp[i][j+1][nc] = max(dp[i][j+1][nc], dp[i][j][x] + g[i][j+1]);
                    }
                }
            }
        }

        int ans = -1;
        for(int i=0;i<=k;i++)
            ans = max(ans, dp[n-1][m-1][i]);

        return ans;
    }
};