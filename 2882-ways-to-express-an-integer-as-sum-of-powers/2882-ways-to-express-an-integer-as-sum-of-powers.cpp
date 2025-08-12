class Solution {
public:
    int numberOfWays(int n, int x) {
        const long long MOD = 1e9+7;
        vector<long long> powers;
        long long p=1;
        for(int i=1; ; i++){
            p=pow(i,x);
            if(p>n) break;
            powers.push_back(p);
        }
       vector<long long> dp(n+1,0);
       dp[0]=1;
       for(int p:powers){
       for(int i=n; i>=p; i--){
         dp[i]=(dp[i]+dp[i-p]) % MOD;
       }
       }
       return (int)dp[n]%MOD;
        
    }
};