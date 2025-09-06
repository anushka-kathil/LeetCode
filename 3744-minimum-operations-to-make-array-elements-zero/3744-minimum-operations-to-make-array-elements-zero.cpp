#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& q) {
        long long ans = 0;
        for (auto &v : q) {
            long long l = v[0], r = v[1];
            ans += (pref(r) - pref(l - 1) + 1) / 2;
        }
        return ans;
    }
private:
    long long pref(long long n) {
        if (n <= 0) return 0;
        long long res = 0, step = 0;
        for (long long b = 1; b <= n; b *= 4) {
            step++;
            long long e = min(n, b * 4 - 1);
            res += (e - b + 1) * step;
        }
        return res;
    }
};
