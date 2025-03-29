class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int row=matrix.size();
        int col=matrix[0].size();
        // first vertical row
        for(int i=0;i<row/2;i++){
            for(int j=0;j<col;j++){
            swap(matrix[i][j], matrix[row-i-1][j]);
            }
        }

         int r=0,c=0;
         while(r<row){
            c=r;
            while(c<col){
            if(r!=c)
            {
               swap(matrix[r][c],matrix[c][r]);
            }
            
            c++;
            }
            r++;
         }
        // transpose matrix

        
    }
};