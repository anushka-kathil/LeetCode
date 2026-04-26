class Solution {
public:
    int n,m;
    vector<vector<int>> vis;
    
    bool dfs(int i,int j,int pi,int pj,vector<vector<char>>& g){
        vis[i][j]=1;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &x:d){
            int ni=i+x[0], nj=j+x[1];
            if(ni<0||nj<0||ni>=n||nj>=m||g[ni][nj]!=g[i][j]) continue;
            if(!vis[ni][nj]){
                if(dfs(ni,nj,i,j,g)) return 1;
            }else if(ni!=pi || nj!=pj){
                return 1;
            }
        }
        return 0;
    }
    
    bool containsCycle(vector<vector<char>>& g) {
        n=g.size(); m=g[0].size();
        vis.assign(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,g)) return 1;
                }
            }
        }
        return 0;
    }
};