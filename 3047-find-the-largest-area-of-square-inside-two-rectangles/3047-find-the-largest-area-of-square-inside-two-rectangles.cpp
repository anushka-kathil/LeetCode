class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                               vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long right  = min(topRight[i][0], topRight[j][0]);
                long long top    = min(topRight[i][1], topRight[j][1]);

                long long w = right - left;
                long long h = top - bottom;

                if (w > 0 && h > 0) {
                    long long side = min(w, h);
                    best = max(best, side * side);
                }
            }
        }
        return best;
    }
};
