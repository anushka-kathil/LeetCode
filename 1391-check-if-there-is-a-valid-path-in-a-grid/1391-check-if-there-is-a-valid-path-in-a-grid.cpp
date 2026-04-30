#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dirs = {
            {},
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
        };
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            int r = curr.first;
            int c = curr.second;
            
            if (r == m - 1 && c == n - 1) return true;
            
            for (auto& d : dirs[grid[r][c]]) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    for (auto& next_d : dirs[grid[nr][nc]]) {
                        if (nr + next_d[0] == r && nc + next_d[1] == c) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            break;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};