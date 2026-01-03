class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9+7;
        long long same = 6;
        long long diff = 6;
        for(int i=2; i<=n; i++){
            long long same_new = (3*same+2*diff)%MOD;
            long long diff_new = (2*same+2*diff)%MOD;
            same=same_new;
            diff=diff_new;
        }
        return (same+diff)%MOD;
    }
};