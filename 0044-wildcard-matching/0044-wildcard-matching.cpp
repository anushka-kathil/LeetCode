class Solution {
public:
    // MEMOIZATION
    // bool f(string pattern, string text, int i, int j, vector<vector<bool>>& dp){
    //     if(i<0 && j<0) return true;
    //     if(i<0) return false;
    //     if(j<0){
    //         for(int k=0; k<=i; k++){
    //             if(pattern[k]!='*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != false) return true;
    //     if(pattern[i] == text[j] || pattern[i] == '?'){
    //         return dp[i][j] = f(pattern,text,i-1,j-1,dp);
    //     }
    //     else if(pattern[i] == '*'){
    //         return dp[i][j] = f(pattern,text,i-1,j,dp) | f(pattern,text,i,j-1,dp);
    //     }
    //     else{
    //     return false;
    //     }
    // }

    bool isMatch(string text, string pattern) {
        int n = pattern.size(); // pattern size
        int m = text.size(); // text size
        // vector<vector<bool>> dp(n,vector<bool>(m,false));
        // return f(pattern,text,n-1,m-1,dp); // memoization 

        // TABULATION
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        // BASE CASES
        dp[0][0] = true;
        for(int j=1; j<=m; j++){
            dp[0][j] = false;
        }
        
        for(int i=1; i<=n; i++){
            bool flag = true;
            for(int k=1; k<=i; k++){
                if(pattern[k-1] != '*') {
                flag = false; 
                break;
                }
            }
            // if(!flag)
            dp[i][0] = flag;
        }
        // base cases ended
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
            dp[i][j] = dp[i-1][j-1];
        }
        else if(pattern[i-1] == '*'){
             dp[i][j] = dp[i-1][j] | dp[i][j-1];
        }
        else{
        dp[i][j] = false;
        }


            }
        }
        return dp[n][m];

        
        
    }
};