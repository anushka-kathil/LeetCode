class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v = {1};
        ans.push_back(v);
        if(numRows == 1) return ans;
        v.clear();
        v = {1,1};
        ans.push_back(v);
        if(numRows == 2) return ans;
        for(int i=3; i<=numRows; i++){
            vector<int> vec;
            vec.push_back(1);
            for(int j=1; j<v.size(); j++){
             vec.push_back(v[j]+v[j-1]);
            }
            vec.push_back(1);
            v = vec;
            ans.push_back(vec);   
        }
        return ans;
    }
};