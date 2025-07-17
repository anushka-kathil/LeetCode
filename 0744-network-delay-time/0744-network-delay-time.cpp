class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        cout<<dist[n];

        queue<pair<int,int>> q;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            int dis = q.front().first;
            int node = q.front().second;
            q.pop();

            for(auto it:adj[node]){
                int adjNode = it.first;
                int time = it.second;
                if((dis + time) < dist[adjNode]){
                    dist[adjNode]=dis + time;
                    q.push({dis + time, adjNode});
                }
            }
        }
        int ans = INT_MIN;

        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            if(dist[i] > ans) ans = dist[i];
        }
        return ans;
        
    }
};