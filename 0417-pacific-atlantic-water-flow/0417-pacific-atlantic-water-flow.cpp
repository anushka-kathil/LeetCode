class Solution {
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for(auto &dir : directions){
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && x < matrix.size() && y >=0 && y < matrix[0].size() 
               && !visited[x][y] && matrix[x][y] >= matrix[i][j]){
                dfs(x, y, matrix, visited);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            dfs(i,0,matrix,pacific);
            dfs(i,n-1,matrix,atlantic);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,matrix,pacific);
            dfs(m-1,j,matrix,atlantic);
        }
        
        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};
