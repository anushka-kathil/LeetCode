class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int maxi=0;
        set<int> s(nums.begin(),nums.end());
        for(auto it=s.begin(); it!=s.end(); it++){
            int e = *it;
            if(m[e-1] == 0 && m[e+1] == 0) continue;
            if(m[e-1]>0 && maxi < (m[e]+m[e-1])) maxi = m[e]+m[e-1];
            if(m[e+1]>0 && maxi < (m[e]+m[e+1])) maxi = m[e]+m[e+1];
        }
        return maxi;   
    
    }
};