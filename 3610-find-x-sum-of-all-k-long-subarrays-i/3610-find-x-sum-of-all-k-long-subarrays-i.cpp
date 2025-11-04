class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int,int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            vector<pair<int,int>> pairs;
            for (auto &p : freq) {
                pairs.push_back({p.second, p.first}); 
            }
            sort(pairs.begin(), pairs.end(), [&](auto &a, auto &b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first > b.first;
            });
            long long currSum = 0;
            for (int t = 0; t < x && t < (int)pairs.size(); t++) {
                currSum += 1LL * pairs[t].first * pairs[t].second;
            }
            ans.push_back((int)currSum);
        }
        return ans;
    }
};
