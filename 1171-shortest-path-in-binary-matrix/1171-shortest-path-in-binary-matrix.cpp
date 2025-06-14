class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1 && grid[0][0] == 0) return 1;
        pair<int,int> start = {0,0};
        if(grid[0][0] == 1) return -1;
        
        pair<int,int> end = {n-1,n-1};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        queue<pair<int, pair<int,int>>> q;
        q.push({1,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int diagr[]={-1,1,1,-1};
        int diagc[]={1,1,-1,-1};
       
        while(!q.empty()){
            int dis = q.front().first;
            int r1 = q.front().second.first;
            int c1 = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r1 + diagr[i];
                int ncol = c1 + diagc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0 && dis+1 < dist[nrow][ncol]){
                    if(nrow == end.first && ncol == end.second) return dis + 1;
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
               
            }

                for(int i=0;i<4;i++){
                    {
                    int nrow = r1 + dr[i];
                    int ncol = c1 + dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0 && dis+1 < dist[nrow][ncol]){
                        if(nrow == end.first && ncol == end.second) return dis + 1;
                        dist[nrow][ncol] = dis+1;
                        q.push({dis+1,{nrow,ncol}});
                        }
                    }
                 }
        }
        return -1;
    }
};