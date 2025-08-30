class Solution {
public:
    bool check(string a, string b){
        if(a.size() - b.size() != 1) return false;
        int l1=0, l2=0;
        while(l1 < a.size()){
            if(a[l1] == b[l2]){
                l1++;
                l2++;
            }
            else{
                l1++;
            }
        }
        if(l1 == a.size() && l2 == b.size()) return true;
        else return false;

    }
    static bool cmp(string& a, string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi=1;
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),cmp);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(check(words[i], words[prev]) && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};