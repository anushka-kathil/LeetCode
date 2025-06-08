class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int c = image[sr][sc];
        
        if(color == c) return image;
        image[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(q.size()){
            int size = q.size();
            
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
           
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nrow = row + drow[j];
                int ncol = col + dcol[j];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol<m && image[nrow][ncol] == c)
                {  image[nrow][ncol] = color;
                    q.push({nrow,ncol});}

              }
            // }
        }
        return image;
        
    }
};