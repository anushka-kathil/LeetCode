class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto& w : walls) grid[w[0]][w[1]] = -1;
        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        vector<vector<int>> vis = grid;
        vector<int> dirs = {0,1,0,-1,0};
        for (auto& g : guards) {
            for (int d = 0; d < 4; ++d) {
                int x = g[0] + dirs[d], y = g[1] + dirs[d+1];
                while (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != -1 && grid[x][y] != 1) {
                    vis[x][y] = 2;
                    x += dirs[d];
                    y += dirs[d+1];
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (vis[i][j] == 0) cnt++;
        return cnt;
    }
};
