class Solution {
public:
    int sum(vector<vector<int>>& triangle, int n, int m, int i,int j,vector<vector<int>>& dp ){
        if(i>=n ) return 0;
        // if(j > i) return 0;
        if(i == (n-1)) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int l = sum(triangle,n,m+1,i+1,j,dp);
        int r = sum(triangle,n,m,i+1,j+1,dp);
        // cout<<triangle[i][j] + min(l,r)<<" ";
        return dp[i][j] = triangle[i][j] + min(l,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m = triangle[0].size();
        if(n == 1 && m==1){
            return triangle[0][0];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sum(triangle,n,m,0,0,dp);
    }
};