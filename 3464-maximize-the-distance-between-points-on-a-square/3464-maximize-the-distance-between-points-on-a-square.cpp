class Solution {
public:
    int maxDistance(int s, vector<vector<int>>& p, int k) {
        vector<long long> a;
        for (auto &v : p) {
            long long x = v[0], y = v[1];
            if (y == 0) a.push_back(x);
            else if (x == s) a.push_back(s + y);
            else if (y == s) a.push_back(3LL*s - x);
            else a.push_back(4LL*s - y);
        }
        
        sort(a.begin(), a.end());
        int n = a.size();
        long long per = 4LL * s;
        
        vector<long long> b = a;
        for (auto x : a) b.push_back(x + per);
        
        auto ok = [&](long long d) {
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                long long first = b[i], last = b[i];
                int pos = i;
                
                while (cnt < k) {
                    long long target = last + d;
                    pos = lower_bound(b.begin() + pos + 1, b.begin() + i + n, target) - b.begin();
                    if (pos >= i + n) break;
                    last = b[pos];
                    cnt++;
                }
                
                if (cnt == k && first + per - last >= d) return true;
            }
            return false;
        };
        
        long long l = 0, r = per;
        while (l <= r) {
            long long m = (l + r) / 2;
            if (ok(m)) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};