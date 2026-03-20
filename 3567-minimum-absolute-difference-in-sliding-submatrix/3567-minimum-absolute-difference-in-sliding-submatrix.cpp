class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        int max_element = (m-k+1)*(n-k+1);
        int row = k;
        // multiset<int> s;
        for(int i = 0; i<=m-k ;i++){
            for(int j=0; j<=n-k; j++){
                set<int> s;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        s.insert(grid[x][y]);
                    }
                }
                if (s.size()==1) {
                    ans[i][j] = 0;
                    continue;
                }
                int diff = INT_MAX;
                auto it = s.begin();
                auto p = it++;
                while (it != s.end()) {
                    diff=min(diff, abs(*it - *p));
                    p=it++;
                }
                ans[i][j]=diff;
            }
            }
        return ans;
            
        
    }
};