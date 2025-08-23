class Solution {
public:
    int minAreaRect(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        int minR = INT_MAX, maxR = INT_MIN;
        int minC = INT_MAX, maxC = INT_MIN;

        for (int r = r1; r <= r2; ++r) {
            for (int c = c1; c <= c2; ++c) {
                if (grid[r][c] == 1) {
                    minR = min(minR, r);  maxR = max(maxR, r);
                    minC = min(minC, c);  maxC = max(maxC, c);
                }
            }
        }
        if (minR == INT_MAX) return 0;                 // no 1s
        return (maxR - minR + 1) * (maxC - minC + 1);  // tight bbox
    }

    int minimumSum(vector<vector<int>>& grid) {
        const int rows = (int)grid.size();
        const int cols = (int)grid[0].size();
        int best = INT_MAX;

        // 3 vertical strips
        for (int c1 = 0; c1 < cols; ++c1) {
            for (int c2 = c1 + 1; c2 < cols; ++c2) {
                int a = minAreaRect(grid, 0, rows - 1, 0, c1);
                int b = minAreaRect(grid, 0, rows - 1, c1 + 1, c2);
                int c = minAreaRect(grid, 0, rows - 1, c2 + 1, cols - 1);
                best = min(best, a + b + c);
            }
        }

        // 3 horizontal strips
        for (int r1 = 0; r1 < rows; ++r1) {
            for (int r2 = r1 + 1; r2 < rows; ++r2) {
                int a = minAreaRect(grid, 0, r1, 0, cols - 1);
                int b = minAreaRect(grid, r1 + 1, r2, 0, cols - 1);
                int c = minAreaRect(grid, r2 + 1, rows - 1, 0, cols - 1);
                best = min(best, a + b + c);
            }
        }

        // Mixed splits (now covering all 4 orientations)
        for (int cc = 0; cc < cols - 1; ++cc) {
            for (int rr = 0; rr < rows - 1; ++rr) {
                // vertical first, split RIGHT side horizontally
                best = min(best,
                    minAreaRect(grid, 0, rows - 1, 0, cc) +
                    minAreaRect(grid, 0, rr, cc + 1, cols - 1) +
                    minAreaRect(grid, rr + 1, rows - 1, cc + 1, cols - 1));

                // **vertical first, split LEFT side horizontally**  (missing before)
                best = min(best,
                    minAreaRect(grid, 0, rr, 0, cc) +
                    minAreaRect(grid, rr + 1, rows - 1, 0, cc) +
                    minAreaRect(grid, 0, rows - 1, cc + 1, cols - 1));

                // horizontal first, split BOTTOM side vertically
                best = min(best,
                    minAreaRect(grid, 0, rr, 0, cols - 1) +
                    minAreaRect(grid, rr + 1, rows - 1, 0, cc) +
                    minAreaRect(grid, rr + 1, rows - 1, cc + 1, cols - 1));

                // **horizontal first, split TOP side vertically**   (missing before)
                best = min(best,
                    minAreaRect(grid, 0, rr, 0, cc) +
                    minAreaRect(grid, 0, rr, cc + 1, cols - 1) +
                    minAreaRect(grid, rr + 1, rows - 1, 0, cols - 1));
            }
        }

        return best;
    }
};
