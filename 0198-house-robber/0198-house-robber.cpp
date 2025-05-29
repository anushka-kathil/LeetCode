class Solution {
public:
    int sol(vector<int>& nums, vector<int>& dp,int index){
      if(index == 0) return nums[index];
      if(index < 0) return 0;
      if(dp[index] != -1) return dp[index];

      int pick = nums[index] + sol(nums,dp,index-2);
      int notpick= 0+sol(nums,dp,index-1);
      return dp[index]=max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return sol(nums,dp,n-1);
        
    }
};