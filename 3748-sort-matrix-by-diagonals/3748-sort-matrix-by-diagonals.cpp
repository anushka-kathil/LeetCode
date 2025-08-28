class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vector<int> v;
                int i1=i,j1=j;
                while(i1>=0 && i1<n && j1>=0 && j1<m){
                    v.push_back(grid[i1][j1]);
                    i1++;
                    j1++;
                }
                if(i==0 && j==0) sort(v.begin(),v.end(),greater<int>());
                else if(i==0)
                sort(v.begin(),v.end());
                else
                sort(v.begin(),v.end(),greater<int>());
                for(auto i:v){
                    cout<<i<<" ";
                }
                cout<<endl;
                i1=i,j1=j;
                int ind=0;
                while(i1>=0 && i1<n && j1>=0 && j1<m){
                    // cout<<v[ind]<<" ";
                    if(ind < v.size()){
                    grid[i1][j1] = v[ind];
                    }

                    ind++;
                    i1++;
                    j1++;
                }

                if(i!=0) break;
                
            }
        }
        return grid;
        
    }
};