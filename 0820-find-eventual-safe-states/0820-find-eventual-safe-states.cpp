class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> safeNodes;
       vector<int> indegree(n,0);
        // int indegree[n]={0};
        for(int i=0; i<n; i++){
            for(auto& it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

        while(q.size()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};