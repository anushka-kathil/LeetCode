class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        unordered_map<string, int> id;
        int idx = 0;

        auto getId = [&](const string& s) {
            if (!id.count(s)) id[s] = idx++;
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int n = idx;
        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        unordered_set<int> lens;
        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
            lens.insert(original[i].size());
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int m = source.size();
        vector<long long> dp(m + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < m; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int len : lens) {
                if (i + len > m) continue;

                string s1 = source.substr(i, len);
                string s2 = target.substr(i, len);

                if (id.count(s1) && id.count(s2)) {
                    long long d = dist[id[s1]][id[s2]];
                    if (d < INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + d);
                    }
                }
            }
        }

        return dp[m] == INF ? -1 : dp[m];
    }
};
