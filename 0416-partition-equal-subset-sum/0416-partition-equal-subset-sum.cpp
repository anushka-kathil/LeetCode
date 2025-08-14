class Solution {
public:
    bool subset(int n, int target, vector<int>& nums,  vector<vector<int>> &dp){
        if(target == 0) return true;
        if(n==0){
            return nums[0] == target;
        }
        if(dp[n][target] != -1) return dp[n][target];
        bool not_take = subset(n-1,target,nums,dp);
        bool take = false;
        if(target >= nums[n]){
            take=subset(n-1, target - nums[n], nums,dp);
        }
        return dp[n][target] = take | not_take;

    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return false;
        int target = sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        return subset(nums.size()-1, target, nums, dp);        
    }
};