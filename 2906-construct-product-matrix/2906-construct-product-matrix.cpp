class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int MOD = 12345;
        
        int size = n * m;
        vector<long long> arr(size), prefix(size, 1), suffix(size, 1);
        
        // Flatten grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i * m + j] = grid[i][j];
            }
        }
        
        // Prefix
        for(int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD;
        }
        
        // Suffix
        for(int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % MOD;
        }
        
        // Build result
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < size; i++) {
            long long val = (prefix[i] * suffix[i]) % MOD;
            res[i / m][i % m] = val;
        }
        
        return res;
    }
};