class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rowMap, colMap;
        for (auto &b : buildings) {
            rowMap[b[0]].push_back(b[1]);
            colMap[b[1]].push_back(b[0]);
        }
        for (auto &p : rowMap) sort(p.second.begin(), p.second.end());
        for (auto &p : colMap) sort(p.second.begin(), p.second.end());

        int cnt = 0;
        for (auto &b : buildings) {
            int r = b[0], c = b[1];
            if (r == 1 || r == n || c == 1 || c == n) continue;

            auto &rows = colMap[c];
            auto &cols = rowMap[r];

            bool up = rows.front() < r;
            bool down = rows.back() > r;
            bool left = cols.front() < c;
            bool right = cols.back() > c;

            if (up && down && left && right) cnt++;
        }
        return cnt;
    }
};
