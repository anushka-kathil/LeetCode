class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long,int> dp;
        return solve(s,0,1,0,k,dp)+1;
    }
private:
    int solve(const string &s,int idx,int can,int mask,int k,unordered_map<long long,int>&dp){
        if(idx==s.size()) return 0;
        long long key=((long long)idx<<27)|((long long)can<<26)|mask;
        if(dp.count(key)) return dp[key];
        int ans=0;
        int bit=1<<(s[idx]-'a');
        ans=max(ans,calc(s,idx,can,mask,bit,k,dp));
        if(can){
            for(int j=0;j<26;j++){
                int nb=1<<j;
                ans=max(ans,calc(s,idx,0,mask,nb,k,dp));
            }
        }
        return dp[key]=ans;
    }
    int calc(const string &s,int idx,int c,int mask,int nb,int k,unordered_map<long long,int>&dp){
        int nm=mask|nb;
        if(__builtin_popcount(nm)>k) return 1+solve(s,idx+1,c,nb,k,dp);
        return solve(s,idx+1,c,nm,k,dp);
    }
};
