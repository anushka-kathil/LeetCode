class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.size();
        int sum=0, e=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==j || i+j == n-1) sum+=mat[i][j];
                // if(i==j && i+j == n-1) e = mat[i][j];
            }
        }
        return sum-e;
        
    }
};