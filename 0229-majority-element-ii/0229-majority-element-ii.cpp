class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int times = n/3;
        cout<<times;
        vector<int> v;
        set<int> s;
        unordered_map<int,int> m(0);
        for(int i=0; i<n; i++){
             m[nums[i]]++;
            if(m[nums[i]] > times) s.insert(nums[i]);
        }
        v.assign(s.begin(), s.end());
        return v; 
    }
};