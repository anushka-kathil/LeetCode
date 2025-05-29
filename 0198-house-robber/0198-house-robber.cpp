class Solution {
public:
// M-1 memorization
    // int sol(vector<int>& nums, vector<int>& dp,int index){
    //   if(index == 0) return nums[index];
    //   if(index < 0) return 0;
    //   if(dp[index] != -1) return dp[index];

    //   int pick = nums[index] + sol(nums,dp,index-2);
    //   int notpick= 0+sol(nums,dp,index-1);
    //   return dp[index]=max(pick,notpick);
    // }

    int rob(vector<int>& nums) {
        // M-1
        int n=nums.size();
        // vector<int> dp(n,-1);
        // return sol(nums,dp,n-1);

        // M-2 with constant space
        int prev=nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;

            int notTake = 0 + prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        
    }
};