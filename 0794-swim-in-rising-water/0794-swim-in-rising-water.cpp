class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<>> pq; 
        vector<vector<int>> vis(n, vector<int> (n, 0));
        pq.push({grid[0][0], 0, 0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto [t,r,c] = pq.top();
            pq.pop();
            if(r == n-1 && c==n-1) return t;
           
            for(int ind=0; ind<4; ind++){
                int nr = r + dr[ind];
                int nc = c + dc[ind];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]) {
                    vis[nr][nc]=1;
                    pq.push({max(t,grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};