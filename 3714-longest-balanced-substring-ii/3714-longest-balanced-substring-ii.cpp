class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int ans = 1;

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) cnt++;
            else cnt = 1;
            ans = max(ans, cnt);
        }

        vector<pair<char,char>> pairs = {
            {'a','b'}, {'a','c'}, {'b','c'}
        };

        for (auto [x, y] : pairs) {
            unordered_map<int,int> mp;
            mp[0] = -1;
            int diff = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] != x && s[i] != y) {
                    mp.clear();
                    mp[0] = i;
                    diff = 0;
                    continue;
                }

                if (s[i] == x) diff++;
                else diff--;

                if (mp.count(diff)) {
                    ans = max(ans, i - mp[diff]);
                } else {
                    mp[diff] = i;
                }
            }
        }

        unordered_map<long long,int> mp;
        mp[0] = -1;

        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            int d1 = a - b;
            int d2 = a - c;

            long long key = ((long long)d1 << 32) ^ (d2 & 0xffffffff);

            if (mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
};
