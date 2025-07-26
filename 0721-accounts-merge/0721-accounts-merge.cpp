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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail]=i;
                }

                else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for(auto it:mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> v;
            v.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                v.push_back(it);
            }
            ans.push_back(v);
        }
         return ans;  
    }
};