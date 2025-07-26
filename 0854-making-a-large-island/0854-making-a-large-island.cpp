class DisjointSet{

 public:
  vector<int> parent, rank, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        int ones=0;
         DisjointSet ds(n*m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                     ones++;
                    for(int ind=0; ind<4; ind++){
                        int adjr = i+dr[ind];
                        int adjc = j+dc[ind];
                        if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && grid[adjr][adjc]==1) {          
                           
                            int u = i*m+j;
                            int v=adjr*m+adjc;
                            ds.unionBySize(u,v);
                        }
                    }
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                set<int> s;
                if(grid[i][j] == 0){
                    for(int ind=0; ind<4; ind++){
                        int adjr = i+dr[ind];
                        int adjc = j+dc[ind];
                        if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && grid[adjr][adjc]==1) {             
                            int v = adjr*m+adjc;
                            int ulp = ds.findUPar(v);
                            // cout<<ulp<<" "<<ds.size[ulp]<<endl;
                            s.insert(ulp);
                        }
                    }
                    // cout<<"**"<<endl;
                    int sum=0;
                     for(auto it:s){
                        // cout<<it<<" ";
                      sum += ds.size[it];
                     }
                     ans=max(ans,sum+1);
                }
            }
        }
        
        if(ones==(n*m)) return n*m;
        // else if(s.size()==0) return 0;
        // for(auto it:s){
        //   ans += ds.size[it];
        // }


        // for(int i=0; i<n*m; i++){
        //     ans=max(ans, ds.size[ds.findUPar(i)]);
        // }

        return ans;  
    }
};