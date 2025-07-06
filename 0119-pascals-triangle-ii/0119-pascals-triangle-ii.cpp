class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex;
        vector<vector<int>> ans;
        vector<int> v = {1};
        ans.push_back(v);
        v.clear();
        v = {1,1};
        ans.push_back(v);
        for(int i=3; i<=numRows+1; i++){
            vector<int> vec;
            vec.push_back(1);
            for(int j=1; j<v.size(); j++){
             vec.push_back(v[j]+v[j-1]);
            }
            vec.push_back(1);
            v = vec;
            ans.push_back(vec);   
        }
        return ans[rowIndex];
    }
};