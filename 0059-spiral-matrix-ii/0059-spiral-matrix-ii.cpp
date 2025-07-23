class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n)); 
    int num = 1;
        int x=0,y=0,dx=1,dy=0;
        vector<vector<bool>> visited(n,vector<bool>(n));
        for(int i=0; i<n*n; i++){
        //   ans.push_back(matrix[y][x]);
          
          matrix[y][x] = num++;
          cout<<matrix[y][x]<<" ";
          visited[y][x] = true;
          if((x+dx < 0 || x+dx >= n) || (y+dy < 0 || y+dy >= n)  || visited[y+dy][x+dx] == true){
            int temp = dx;
            dx = -dy;
            dy = temp;
          }
          x+=dx;
          y+=dy;
        }
       
        return matrix;
        
    }
};