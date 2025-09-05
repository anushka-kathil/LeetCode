class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& grid, int& ans, int n, int m){
           
           if(vis[i][j] == 1) return;
           vis[i][j] = 1;
           int dx[4] = {-1,0,1,0};
           int dy[4] = {0,1,0,-1};
           ans++;
           for(int dir = 0; dir<4; dir++){
                    int nr = i+dx[dir];
                    int nc = j+dy[dir];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=1){
                        dfs(nr,nc,vis,grid,ans,n,m);
                 }
            }
            return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0, res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=0;
                if(grid[i][j] == 0) continue;
                // ans++;
                dfs(i,j,vis,grid,ans,n,m); 
                res = max(res,ans);
            }
        }
        return res;
        
    }
};