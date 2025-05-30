class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == triangle.size() - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = dfs(i + 1, j, triangle, dp);
        int diagonal = dfs(i + 1, j + 1, triangle, dp);
        
        dp[i][j] = triangle[i][j] + min(down, diagonal);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, 0, triangle, dp);
    }
};
