class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int val = nums[q];
            auto &v = pos[val];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();

            int best = INT_MAX;
            int next = v[(idx + 1) % v.size()];
            best = min(best, min(abs(next - q), n - abs(next - q)));
            int prev = v[(idx - 1 + v.size()) % v.size()];
            best = min(best, min(abs(prev - q), n - abs(prev - q)));

            ans.push_back(best);
        }

        return ans;
    }
};