class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        
        // prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1] 
                            + pref[i-1][j] 
                            + pref[i][j-1] 
                            - pref[i-1][j-1];
            }
        }

        auto possible = [&](int len) {
            for (int i = len; i <= m; i++) {
                for (int j = len; j <= n; j++) {
                    int sum = pref[i][j] - pref[i-len][j] - pref[i][j-len] + pref[i-len][j-len];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
