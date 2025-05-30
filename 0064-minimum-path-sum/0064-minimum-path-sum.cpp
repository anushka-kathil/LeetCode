class Solution {
public:
    int sum (vector<vector<int>>& grid, int m ,int n, int i, int j, int s, vector<vector<int>>& dp){
        if(i>=m || j>=n) return INT_MAX;
        if(i==(m-1) && j==(n-1)) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];
        int l = sum(grid,m,n,i+1,j,s,dp);
        int r = sum(grid,m,n,i,j+1,s,dp);
        s = grid[i][j] + min(l,r);
        dp[i][j] = s;
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return sum (grid,m,n,0,0,0,dp);    
    }
};