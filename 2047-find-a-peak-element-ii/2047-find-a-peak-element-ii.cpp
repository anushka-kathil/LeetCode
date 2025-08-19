class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                flag = false;
                for(int k=0; k<4; k++){
                    int r = i+dr[k];
                    int c = j+dc[k];
                    if(r>=0 && r<n && c>=0 && c<m && mat[i][j] < mat[r][c]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    return {i,j};
                }
            }
        }
        return {-1};
        
    }
};