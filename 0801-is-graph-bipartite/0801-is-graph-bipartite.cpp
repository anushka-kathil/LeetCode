class Solution {
private:
    bool check(int s,vector<int>& color,vector<vector<int>>& graph){
         int n = graph.size();
       
        queue<int> q;
        q.push(s);
        color[s] = 0;
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it]= !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
       // if components present
       for(int i=0;i<n;i++){
          if(color[i] == -1){
            if(check(i,color,graph) == false)
            return false;
          }
       }
       return true;
    }
};