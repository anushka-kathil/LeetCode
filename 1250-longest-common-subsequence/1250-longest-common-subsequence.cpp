class Solution {
public:
    // int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
        // MEMOIZATION
    //     if(ind1<0 || ind2<0) return 0;
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(s1[ind1] == s2[ind2]){
    //         return dp[ind1][ind2]=1+solve(ind1-1, ind2-1, s1, s2,dp);
    //     }
    //     else 
    //     return dp[ind1][ind2]=0+max(solve(ind1-1, ind2, s1, s2,dp), solve(ind1, ind2-1, s1, s2,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        // Memoization
        // vector<vector<int>> dp(s1,vector<int>(s2,-1));
        // return solve(s1-1, s2-1, text1, text2, dp);

        // TABULATION
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,-1));
        for(int i=0; i<=s1; i++) dp[i][0] = 0;
        for(int j=0; j<=s2; j++) dp[0][j] = 0;
        for(int ind1=1; ind1<=s1; ind1++){
            for(int ind2=1; ind2<=s2; ind2++){
                 if(text1[ind1-1] == text2[ind2-1]){ // index shifting
                 dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
           }
        else 
        dp[ind1][ind2]=0+max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[s1][s2];
    }
};