class Solution {
public:
    // int f(int ind, int n, vector<int>& prices, int profit,vector<vector<int>>& dp, int buy ){
    //     if(ind == n) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];

    //     if(buy){
    //         profit=max(-prices[ind]+f(ind+1,n,prices,profit,dp,0), 0+f(ind+1,n,prices,profit,dp,1));
    //     }
    //     else{
    //         profit = max(prices[ind]+f(ind+1,n,prices,profit,dp,1), 0+f(ind+1,n,prices,profit,dp,0));
    //     }
    //     return dp[ind][buy]= profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1)); // memoization


        // TABULATION
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
            profit=max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
        }
        else{
            profit = max(prices[ind]+dp[ind+1][1], 0+dp[ind+1][0]);
        }
              dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
        
    }
};