class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> *adj = new vector<int>[N];
        // int adj[numCourses];
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        // check for topological sort
        // int indegree[N];
        vector<int> indegree(N,0);
        // int* indegree = new int[N];
        // vector<int> *indegree = new vector<int>[N];
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> topo;
        while(q.size()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
          for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
          }
        }

        if(topo.size() == N)
        return true;

        return false;
        
    }
};