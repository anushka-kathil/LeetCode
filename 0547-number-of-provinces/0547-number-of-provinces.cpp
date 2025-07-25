class DisjointSet{
 vector<int> parent, rank, size;
 public:
 
 // constructor
 DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0; i<=n; i++){
        parent[i]=i;
        size[i] = 1;
    }
 }

 int findUPar(int node){
    // cout<<parent[node]<<"->"<<node<<endl;
    if(parent[node] == node) return node;

    return parent[node] = findUPar(parent[node]);
 }

 void unionByRank(int u, int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if(ulp_u == ulp_v) return; // they are in same component
    if(rank[ulp_u] == rank[ulp_v]){
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }

    else if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
    }

    else{
        parent[ulp_v] = ulp_u;
    }
 }
  
  void unionBySize(int u, int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if(ulp_u == ulp_v) return; // they are in same component

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v]+= size[ulp_u];
    }
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u]+=size[ulp_v];
    }    
  }
};

class Solution {
    private:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis){
      vis[node]=1;
      for(auto it : adjLs[node]){
       if(!vis[it]){
        dfs(it, adjLs, vis);
       }
      }
   }
  
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       DisjointSet ds(n);
       for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(isConnected[i][j] == 1){
            ds.unionBySize(i+1,j+1);
          }
        }
       }
       int cnt=0;
       for(int i=1; i<=n; i++){
        if(ds.findUPar(i) == i){ 
        cnt++;}
       }
       return cnt;
    }
};



