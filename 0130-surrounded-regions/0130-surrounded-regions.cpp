class Solution {
public:

   void dfs(int i, int j,vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m, int drow[], int dcol[]){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
          dfs(nrow,ncol,board,vis,n,m,drow,dcol);
    }

   }
    

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        // row
        for(int j=0;j<m;j++){
            if(!vis[0][j] &&  board[0][j] == 'O'){
                dfs(0,j,board,vis,n,m,drow,dcol);
            }

            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,board,vis,n,m,drow,dcol);
            }
        }
         // column
        for(int i=0;i<n;i++){
            if(!vis[i][0] &&  board[i][0] == 'O'){
                dfs(i,0,board,vis,n,m,drow,dcol);
            }

            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,board,vis,n,m,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
        return;
        
    }
};