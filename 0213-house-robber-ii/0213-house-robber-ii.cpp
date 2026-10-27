class Solution {
public:
    int f(vector<int>& nums, int n, vector<int>& dp){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = nums[n]+f(nums,n-2,dp);
        int notPick = 0+f(nums,n-1,dp);
        return dp[n]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {  
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t1,t2;
        // vector<int> dp(n,-1);
        for(int i=0; i<n; i++){
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        vector<int> dp1(n-1, -1), dp2(n-1, -1);
        return max(f(t1, n-2, dp1), f(t2, n-2, dp2));        
    }
};