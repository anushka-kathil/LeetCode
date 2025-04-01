class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> ans;
        vector<int> v;
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                v.push_back(matrix[j][i]);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
        
    }
};