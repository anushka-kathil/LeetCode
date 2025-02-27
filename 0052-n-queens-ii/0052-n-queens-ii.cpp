class Solution {

public:
    bool isSafe(int col,int row,  vector<string>& board,int n){
        // No need to check for upper and lower board[row][col]
        int duprow=row;
        int dupcol=col;
       // Checking left upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        // left side
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
      
       
        // checking lower left diagonal
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }


public:
    void solve(int col,int n, vector<vector<string>>& ans, vector<string>& board){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(col,row,board,n)){
                board[row][col]='Q';
                solve(col+1,n,ans,board);
                board[row][col]='.';
            }
        }
       
    }

public:
    int totalNQueens(int n) {
         vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        // vector<int> leftRow(n,0), upperDiagonal(2*n -1 ,0), lowerDiagonal(2*n-1,0);
        solve(0,n,ans,board);
        return ans.size();
        
    }
};