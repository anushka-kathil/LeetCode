class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,bool> mp;

        for(int i=0; i<n-1; i++){
            if(mp[nums[i] + nums[i+1]] == false)
            mp[nums[i] + nums[i+1]] = true;

            else return true;
        }

        return false;
    }
};