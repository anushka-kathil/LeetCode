class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
        int element=nums[i];
        if(m.find(element) != m.end() && i-m[element] <= k){
            return true;    
        }
        m[element] = i;
        }
        return false;
    }
};