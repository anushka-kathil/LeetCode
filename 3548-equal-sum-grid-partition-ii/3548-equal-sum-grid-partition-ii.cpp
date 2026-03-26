#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long totalSum = 0;
        unordered_map<int, int> totalCount;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
                totalCount[grid[i][j]]++;
            }
        }

        long long topSum = 0;
        unordered_map<int, int> topCount;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                topSum += grid[i][j];
                topCount[grid[i][j]]++;
            }
            if (isValid(topSum, totalSum - topSum, i + 1, n, topCount, totalCount, grid, true, i)) return true;
        }

        long long leftSum = 0;
        unordered_map<int, int> leftCount;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                leftSum += grid[i][j];
                leftCount[grid[i][j]]++;
            }
            if (isValid(leftSum, totalSum - leftSum, m, j + 1, leftCount, totalCount, grid, false, j)) return true;
        }

        return false;
    }

private:
    bool isValid(long long s1, long long s2, int r1, int c1, unordered_map<int, int>& count1, 
                 unordered_map<int, int>& totalCount, vector<vector<int>>& grid, bool isHoriz, int cutIdx) {
        if (s1 == s2) return true;

        int m = grid.size(), n = grid[0].size();
        int r2 = isHoriz ? m - r1 : m;
        int c2 = isHoriz ? n : n - c1;

        if (s1 > s2) {
            long long diff = s1 - s2;
            if (diff <= 100000 && count1[diff] > 0) {
                if (canRemove(diff, r1, c1, grid, isHoriz, cutIdx, true)) return true;
            }
        }
        if (s2 > s1) {
            long long diff = s2 - s1;
            if (diff <= 100000 && (totalCount[diff] - count1[diff] > 0)) {
                if (canRemove(diff, r2, c2, grid, isHoriz, cutIdx, false)) return true;
            }
        }
        return false;
    }

    bool canRemove(long long val, int r, int c, vector<vector<int>>& grid, bool isHoriz, int cutIdx, bool isPart1) {
        if (r > 1 && c > 1) return true;
        
        if (isHoriz) {
            int startR = isPart1 ? 0 : cutIdx + 1;
            int endR = isPart1 ? cutIdx : grid.size() - 1;
            
            if (c == 1) {
                if (grid[startR][0] == val || grid[endR][0] == val) return true;
            } else {
                if (grid[startR][0] == val || grid[startR][grid[0].size() - 1] == val) return true;
            }
        } else {
            int startC = isPart1 ? 0 : cutIdx + 1;
            int endC = isPart1 ? cutIdx : grid[0].size() - 1;

            if (r == 1) {
                if (grid[0][startC] == val || grid[0][endC] == val) return true;
            } else {
                if (grid[0][startC] == val || grid[grid.size() - 1][startC] == val) return true;
            }
        }
        return false;
    }
};