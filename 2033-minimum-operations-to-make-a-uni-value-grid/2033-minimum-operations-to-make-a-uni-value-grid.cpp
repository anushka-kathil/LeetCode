class Solution {
public:
    int minOperations(vector<vector<int>>& g, int x) {
        vector<int> v;
        for(auto &r: g) for(auto &e: r) v.push_back(e);
        int r = v[0] % x;
        for(auto &e: v) if(e % x != r) return -1;
        sort(v.begin(), v.end());
        int m = v[v.size()/2], ans = 0;
        for(auto &e: v) ans += abs(e - m) / x;
        return ans;
    }
};