class Solution {
public:
    int f(int ind, int n, vector<int>& prices, int profit,vector<vector<int>>& dp, int buy ){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy){
            profit=max(-prices[ind]+f(ind+1,n,prices,profit,dp,0), 0+f(ind+1,n,prices,profit,dp,1));
        }
        else{
            profit = max(prices[ind]+f(ind+1,n,prices,profit,dp,1), 0+f(ind+1,n,prices,profit,dp,0));
        }
        return dp[ind][buy]= profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,n,prices,0,dp,1);
        
    }
};