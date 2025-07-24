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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       
        // int n = connections.size();
        if (connections.size() < n - 1) return -1; 
        DisjointSet ds(n);
        int k = connections.size();
        for(int i=0; i<k; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionBySize(u,v);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(ds.findUPar(i) == i) cnt++;
        }
       
         return cnt-1;

    }
};