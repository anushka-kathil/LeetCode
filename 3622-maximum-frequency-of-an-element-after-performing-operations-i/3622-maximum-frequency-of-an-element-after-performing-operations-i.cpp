#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> cnt;
        map<long long,int> diff;
        set<long long> candidates;

        for (int v : nums) {
            cnt[v]++;
            long long L = (long long)v - k;
            long long R = (long long)v + k;
            diff[L]++;
            diff[R + 1]--;
            candidates.insert(v);
            candidates.insert(L);
            candidates.insert(R + 1);
        }

        int ans = 1;
        long long reachable = 0;
        auto it = diff.begin();

        for (long long pos : candidates) {
            while (it != diff.end() && it->first <= pos) {
                reachable += it->second;
                ++it;
            }
            int cnt_at_pos = 0;
            if (pos >= INT_MIN && pos <= INT_MAX) {
                auto itc = cnt.find((int)pos);
                if (itc != cnt.end()) cnt_at_pos = itc->second;
            }
            int bestForPos = (int)min<long long>(reachable, (long long)cnt_at_pos + numOperations);
            ans = max(ans, bestForPos);
        }
        return ans;
    }
};
