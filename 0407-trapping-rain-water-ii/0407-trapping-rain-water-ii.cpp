#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if(m <= 2 || n <= 2) return 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n));
        for(int i=0;i<m;i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});
            vis[i][0]=vis[i][n-1]=1;
        }
        for(int j=0;j<n;j++){
            pq.push({heightMap[0][j],0,j});
            pq.push({heightMap[m-1][j],m-1,j});
            vis[0][j]=vis[m-1][j]=1;
        }
        int ans=0, mx=INT_MIN;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto v=pq.top();pq.pop();
            int h=v[0],x=v[1],y=v[2];
            mx=max(mx,h);
            for(auto &dd:d){
                int nx=x+dd[0],ny=y+dd[1];
                if(nx<0||ny<0||nx>=m||ny>=n||vis[nx][ny]) continue;
                vis[nx][ny]=1;
                if(heightMap[nx][ny]<mx) ans+=mx-heightMap[nx][ny];
                pq.push({heightMap[nx][ny],nx,ny});
            }
        }
        return ans;
    }
};
