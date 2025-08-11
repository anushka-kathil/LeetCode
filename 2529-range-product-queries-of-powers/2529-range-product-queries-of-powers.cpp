class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        long long i = 0;
        const long long MOD = 1e9 + 7;
        vector<long long> powers;
        vector<int> v;

        while (n) {
            if (n & 1LL) {
                powers.push_back(1LL << i);
            }
            i++;
            n >>= 1LL;
        }

        long long ans = 1;
        for (auto &query : queries) {
            ans = 1;
            for (long long j = query[0]; j <= query[1]; j++) {
                ans = (ans* powers[j]) % MOD;
            }
            v.push_back(ans);
        }
        return v;
    }
};
