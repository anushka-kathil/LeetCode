class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                st.insert(grid[i][j]);

                for (int k = 1; k < max(m, n); k++) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n)
                        break;

                    int sum = 0;

                    int x = i - k, y = j;

                    for (int d = 0; d < k; d++) sum += grid[x + d][y + d];
                    for (int d = 0; d < k; d++) sum += grid[x + k + d][y + k - d];
                    for (int d = 0; d < k; d++) sum += grid[x + 2*k - d][y - d];
                    for (int d = 0; d < k; d++) sum += grid[x + k - d][y - k + d];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};