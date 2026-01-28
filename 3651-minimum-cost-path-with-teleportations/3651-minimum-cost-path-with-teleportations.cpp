class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        using ll = long long;
        const ll INF = LLONG_MAX / 4;

        vector<tuple<int,int,int>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});
        sort(cells.begin(), cells.end());

        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(k + 1, INF)));
        vector<int> ptr(k + 1, 0);

        priority_queue<tuple<ll,int,int,int>, vector<tuple<ll,int,int,int>>, greater<>> pq;
        dist[0][0][k] = 0;
        pq.push({0, 0, 0, k});

        while (!pq.empty()) {
            auto [cost, i, j, r] = pq.top();
            pq.pop();
            if (cost != dist[i][j][r]) continue;
            if (i == m - 1 && j == n - 1) return cost;

            if (i + 1 < m) {
                ll nc = cost + grid[i + 1][j];
                if (nc < dist[i + 1][j][r]) {
                    dist[i + 1][j][r] = nc;
                    pq.push({nc, i + 1, j, r});
                }
            }

            if (j + 1 < n) {
                ll nc = cost + grid[i][j + 1];
                if (nc < dist[i][j + 1][r]) {
                    dist[i][j + 1][r] = nc;
                    pq.push({nc, i, j + 1, r});
                }
            }

            if (r > 0) {
                while (ptr[r] < cells.size() && get<0>(cells[ptr[r]]) <= grid[i][j]) {
                    auto [v, x, y] = cells[ptr[r]++];
                    if (cost < dist[x][y][r - 1]) {
                        dist[x][y][r - 1] = cost;
                        pq.push({cost, x, y, r - 1});
                    }
                }
            }
        }

        ll ans = INF;
        for (int r = 0; r <= k; r++)
            ans = min(ans, dist[m - 1][n - 1][r]);

        return ans;
    }
};
