class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            if (num == 2) {        
                ans.push_back(-1);
                continue;
            }
            int bit = 1;
            while (num & bit) bit <<= 1;   
            bit >>= 1;                     
            ans.push_back(num - bit);
        }
        return ans;
    }
};
