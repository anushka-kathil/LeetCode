#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calcGain = [&](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto &c : classes) {
            pq.push({calcGain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++, t++;
            pq.push({calcGain(p, t), {p, t}});
        }

        double ans = 0.0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            ans += (double)cur.second.first / cur.second.second;
        }
        return ans / classes.size();
    }
};
