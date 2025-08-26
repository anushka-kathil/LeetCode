class Solution {
public:
    int solve(string s, string t, int i, int j, vector<vector<int>>& dp){
       if(i<0 || j<0) return 0;
       if(dp[i][j] != -1) return dp[i][j];
       if(s[i] == t[j]){
        return dp[i][j] =1+ solve(s,t,i-1,j-1,dp);
       }
       else{
       return dp[i][j] = max(solve(s,t,i-1,j,dp), solve(s,t,i,j-1,dp));
       }
        
        // return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int k = solve(word1,word2,n-1,m-1,dp);
        // cout<<k<<endl;
        return n-k+m-k;
        // return max(n,m) - k;     
    }
};