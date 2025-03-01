class Solution {
public:
bool isValid(vector<vector<char>>& board,int row,int col,char c){
    for(int i=0;i<9;i++){
        // checking in row
        if(board[row][i] == c && col!=i)
        return false;

        // checking in col
        if(board[i][col] == c && row!=i)
        return false;

        // checking in 3*3
        // formula is ROW -> [3*row/3 + i/3], COL -> [3*col/3 + i%3]
        int row1=3*(row/3) + i/3;
        int col1=3*(col/3) + i%3;

        if(row1==row && col1==col)
        continue;

        else if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c){
        return false;}

    }
    return true;
  }
  
   bool solve(vector<vector<char>>& board){
    for(int row=0; row< board.size(); row++){
        for(int col=0;col<board[0].size();col++){
            if(board[row][col]=='.') continue;
                   char c=board[row][col];
                    if(isValid(board,row,col,c)){ 
                    // board[row][col]=c;
                    continue;
                    }
                  return false;  
        }
    }
    return true;
   }

    bool isValidSudoku(vector<vector<char>>& board) {
         return solve(board);
        
    }
};