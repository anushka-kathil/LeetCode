class Solution {
public:
    void dfs(vector<int>& nums, int target, int i, int sum, int &cnt) {
        if (i == nums.size()) {
            if (sum == target) cnt++;
            return;
        }
        dfs(nums, target, i + 1, sum + nums[i], cnt); 
        dfs(nums, target, i + 1, sum - nums[i], cnt); 
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt = 0;
        dfs(nums, target, 0, 0, cnt);
        return cnt;
    }
};
