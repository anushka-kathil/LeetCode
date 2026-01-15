class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        sort(a.begin(), a.end());
        int best = 1, cur = 1;

        for (int i = 1; i < (int)a.size(); i++) {
            if (a[i] == a[i - 1] + 1) {
                cur++;
            } else if (a[i] != a[i - 1]) {
                cur = 1;
            }
            best = max(best, cur);
        }
        return best;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = hBars.empty() ? 0 : longestConsecutive(hBars);
        int maxV = vBars.empty() ? 0 : longestConsecutive(vBars);

        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};
