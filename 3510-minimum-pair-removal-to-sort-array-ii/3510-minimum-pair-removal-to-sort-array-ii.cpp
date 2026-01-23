#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return 0;

        vector<int> nxt(n), prv(n);
        vector<long long> val(n);
        for (int i = 0; i < n; i++) {
            val[i] = nums[i];
            nxt[i] = i + 1;
            prv[i] = i - 1;
        }

        auto comp = [](const pair<long long,int>& a, const pair<long long,int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        };
        set<pair<long long,int>, decltype(comp)> st(comp);

        for (int i = 0; i < n - 1; i++)
            st.insert({val[i] + val[i + 1], i});

        int inv = 0;
        for (int i = 0; i < n - 1; i++)
            if (val[i] > val[i + 1]) inv++;

        int ans = 0;

        while (inv > 0) {
            ans++;

            auto [sum, i] = *st.begin();
            st.erase(st.begin());

            int j = nxt[i];
            if (j >= n) continue;

            int L = prv[i];
            int R = nxt[j];

            if (L != -1) {
                st.erase({val[L] + val[i], L});
                if (val[L] > val[i]) inv--;
            }
            if (R < n) {
                st.erase({val[j] + val[R], j});
                if (val[j] > val[R]) inv--;
            }
            if (val[i] > val[j]) inv--;

            val[i] = val[i] + val[j];

            nxt[i] = R;
            if (R < n) prv[R] = i;

            if (L != -1) {
                st.insert({val[L] + val[i], L});
                if (val[L] > val[i]) inv++;
            }
            if (R < n) {
                st.insert({val[i] + val[R], i});
                if (val[i] > val[R]) inv++;
            }
        }
        return ans;
    }
};
