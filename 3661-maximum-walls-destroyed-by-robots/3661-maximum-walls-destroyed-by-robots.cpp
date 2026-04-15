class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[robots[i]] = distance[i];
        }

        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        vector<int> L(n), R(n), mid(n);

        for (int i = 0; i < n; i++) {
            int x = robots[i];
            int d = mp[x];

            int up = upper_bound(walls.begin(), walls.end(), x) - walls.begin();

            int lBound = (i > 0) ? max(x - d, robots[i - 1] + 1) : x - d;
            int low = lower_bound(walls.begin(), walls.end(), lBound) - walls.begin();
            L[i] = up - low;

            int rBound = (i < n - 1) ? min(x + d, robots[i + 1] - 1) : x + d;
            int rIdx = upper_bound(walls.begin(), walls.end(), rBound) - walls.begin();
            int start = lower_bound(walls.begin(), walls.end(), x) - walls.begin();
            R[i] = rIdx - start;

            if (i > 0) {
                int prev = lower_bound(walls.begin(), walls.end(), robots[i - 1]) - walls.begin();
                mid[i] = up - prev;
            }
        }

        int dpL = L[0], dpR = R[0];

        for (int i = 1; i < n; i++) {
            int nextL = max(dpL + L[i],
                            dpR - R[i - 1] + min(L[i] + R[i - 1], mid[i]));
            int nextR = max(dpL + R[i],
                            dpR + R[i]);

            dpL = nextL;
            dpR = nextR;
        }

        return max(dpL, dpR);
    }
};