class Solution {
public:

    void permutation(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans,unordered_map<int,bool>& m){ 
    if(v.size()==nums.size()){
        ans.push_back(v);
        return;
    }

    for(int i=0;i<nums.size();i++ ){
        if(m[i] == true) continue;
        if (i > 0 && nums[i] == nums[i - 1] && m[i - 1] == false) continue;
        
            v.push_back(nums[i]);
            m[i]=true;
            permutation(nums,v,ans,m);
            v.pop_back();
            m[i]=false;

    }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<int> v;
        vector<vector<int>> ans;
        unordered_map<int,bool> m;
        sort(nums.begin(),nums.end());

        permutation(nums,v,ans,m);
        return ans;
        
        
        
    }
};