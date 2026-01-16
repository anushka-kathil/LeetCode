class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // Add border fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // All possible distances in horizontal direction
        unordered_set<int> dx;
        for (int i = 0; i < (int)hFences.size(); i++) {
            for (int j = i + 1; j < (int)hFences.size(); j++) {
                dx.insert(hFences[j] - hFences[i]);
            }
        }

        long long best = -1;

        // Check vertical distances and match with horizontal
        for (int i = 0; i < (int)vFences.size(); i++) {
            for (int j = i + 1; j < (int)vFences.size(); j++) {
                int d = vFences[j] - vFences[i];
                if (dx.count(d)) best = max(best, (long long)d);
            }
        }

        if (best == -1) return -1;

        return (best * best) % MOD;
    }
};
