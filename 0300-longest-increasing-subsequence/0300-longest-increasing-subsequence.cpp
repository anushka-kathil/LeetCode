class Solution {
public:
    int f(int len, int last, int ind, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == len){ 
            return 0;
            }
            if(dp[ind][last+1]!=-1) return dp[ind][last+1];
       
       int notTake = f(len, last, ind+1, nums,dp);
       int take = 0;
       if(last == -1 || nums[ind] > nums[last]){
        take = 1+f(len,ind, ind+1, nums,dp);
       }
       return dp[ind][last+1]=max(take,notTake);
        // return max(1+ f(len,nums[ind], ind+1, nums), 0+ f(len, last, ind+1, nums));
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int> (len+1,-1));
        return f(len,-1,0, nums,dp);
        
    }
};