class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx, vector<vector<bool>>& vis) {
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(vis[i][j] || board[i][j] != word[idx]) return false;

        vis[i][j] = true;

        bool found = dfs(board, word, i+1, j, idx+1, vis) ||
                     dfs(board, word, i-1, j, idx+1, vis) ||
                     dfs(board, word, i, j+1, idx+1, vis) ||
                     dfs(board, word, i, j-1, idx+1, vis);

        vis[i][j] = false; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
