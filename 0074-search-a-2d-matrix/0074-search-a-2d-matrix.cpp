class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int row = -1;

        if (target < matrix[0][0] || target > matrix[r - 1][c - 1]) {
            return false;
        }

        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == target) {
                return true;
            } else if (target < matrix[i][0]) {
                row = i - 1;
                break;
            }
        }

        if (row == -1) {
            row = r - 1;
        }

        int start = 0, end = c - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};
