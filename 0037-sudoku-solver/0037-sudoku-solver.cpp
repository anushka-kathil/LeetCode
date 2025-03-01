class Solution {
public:
  bool isValid(vector<vector<char>>& board,int row,int col,char c){
    for(int i=0;i<9;i++){
        // checking in row
        if(board[row][i] == c)
        return false;

        // checking in col
        if(board[i][col] == c)
        return false;

        // checking in 3*3
        // formula is ROW -> [3*row/3 + i/3], COL -> [3*col/3 + i%3]
        if(board[3* (row/3) + i/3][3*(col/3) + i%3] == c)
        return false;

    }
    return true;
  }
  
   bool solve(vector<vector<char>>& board){

    for(int row=0; row< board.size(); row++){
        for(int col=0;col<board[0].size();col++){
            if(board[row][col]=='.'){

                for(char c='1';c<='9';c++){
                    if(isValid(board,row,col,c)){ 
                    board[row][col]=c;

                    if(solve(board))
                    return true;
                    
                    else 
                     board[row][col]='.';
                    }
                }
                  return false;
            }
        }
    }
    return true;
   }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};