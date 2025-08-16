#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_set<string> prefixSet;

        for (string &w : words) {
            string pref = "";
            for (char c : w) {
                pref += c;
                prefixSet.insert(pref);
            }
        }

        unordered_set<string> found;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        function<void(int,int,string&)> dfs = [&](int i, int j, string &curr) {
            if (!prefixSet.count(curr)) return;

            if (wordSet.count(curr)) found.insert(curr);

            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    curr.push_back(board[ni][nj]);
                    dfs(ni, nj, curr);
                    curr.pop_back();
                    vis[ni][nj] = 0;
                }
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string curr = "";
                curr.push_back(board[i][j]);
                vis[i][j] = 1;
                dfs(i, j, curr);
                vis[i][j] = 0;
            }
        }

        return vector<string>(found.begin(), found.end());
    }
};
