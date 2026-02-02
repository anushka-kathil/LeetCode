class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = LLONG_MAX;
        long long currSum = 0;

        multiset<int> small, large;

        auto add = [&](int x) {
            small.insert(x);
            currSum += x;

            if ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                currSum -= *it;
                large.insert(*it);
                small.erase(it);
            }
        };

        auto remove = [&](int x) {
            if (small.find(x) != small.end()) {
                currSum -= x;
                small.erase(small.find(x));
            } else {
                large.erase(large.find(x));
            }

            if ((int)small.size() < k - 1 && !large.empty()) {
                auto it = large.begin();
                currSum += *it;
                small.insert(*it);
                large.erase(it);
            }
        };

        int n = nums.size();

        for (int i = 1; i <= dist + 1 && i < n; i++) {
            add(nums[i]);
        }

        ans = nums[0] + currSum;

        for (int i = dist + 2; i < n; i++) {
            add(nums[i]);
            remove(nums[i - dist - 1]);
            ans = min(ans, nums[0] + currSum);
        }

        return ans;
    }
};
