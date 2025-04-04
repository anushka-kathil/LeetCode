class Solution {
public:
    void combination(int index, int target, vector<int>& v, vector<int>& candidates, vector<vector<int>>& ans, int n){
        if(index == n){
            if(target == 0){
            ans.push_back(v);
            }
            return;
        }
        // if(target == 0){ 
        //     ans.push_back(v);
        // }
        // to pick an element
      if(candidates[index] <= target){
        v.push_back(candidates[index]);
        combination(index, target - candidates[index], v, candidates, ans,n);
         v.pop_back();
      }
     
        combination(index+1, target, v, candidates,ans,n);

      


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<int> v;
        int n= candidates.size();

        vector<vector<int>> ans;

       combination(index, target,v, candidates, ans,n);
       return ans;



    }
};