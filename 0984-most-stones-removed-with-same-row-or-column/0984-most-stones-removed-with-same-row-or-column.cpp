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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol+1);
        unordered_map <int,int> m;
        for(auto it:stones){
            int r1=it[0];
            int c1=it[1]+maxRow+1;
            ds.unionBySize(r1,c1);
            m[r1]=1;
            m[c1]=1;
        }
        int cnt=0;

        for(auto it:m){
            if(ds.findUPar(it.first) == it.first) cnt++;
        }
        return n-cnt;
    }
};