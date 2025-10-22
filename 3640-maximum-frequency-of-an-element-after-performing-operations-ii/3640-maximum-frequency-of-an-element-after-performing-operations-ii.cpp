#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if(nums.empty()) return 0;
        unordered_map<long long,int> count;
        map<long long,long long> line;
        set<long long> candidates;
        for(long long x : nums){
            ++count[x];
            ++line[x - k];
            --line[x + k + 1];
            candidates.insert(x);
            candidates.insert(x - k);
            candidates.insert(x + k + 1);
        }
        int ans = 1;
        long long adjustable = 0;
        for(long long v : candidates){
            if(line.count(v)) adjustable += line[v];
            int cnt = count.count(v) ? count[v] : 0;
            long long adjusted = adjustable - cnt;
            ans = max(ans, cnt + (int)min<long long>(numOperations, max(0LL, adjusted)));
        }
        return ans;
    }
};
