class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2(s.rbegin(), s.rend());
  vector<int> prev(n+1, 0), curr(n+1,0);
        // for(int i=0; i<=s1; i++) dp[i][0] = 0;
        // for(int j=0; j<=n; j++) prev[j] = 0;
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                 if(s[ind1-1] == s2[ind2-1]){ // index shifting
                 curr[ind2]=1+prev[ind2-1];
           }
        else 
        curr[ind2]=0+max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[n];
    }

    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};