class Solution {
public:
   void solve(int i,vector<int> &res, vector<vector<int>> &ans, vector<int> &v, int k){
    if(res.size() == k){
        ans.push_back(res);
        return;
    }
    if(i==v.size()) return;
    
    res.push_back(v[i]);
    solve(i+1,res,ans,v,k);
    res.pop_back();
    solve(i+1,res,ans,v,k);
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,res,ans,v,k);
        return ans;
        
    }
};