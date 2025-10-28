class Solution {
public:
    long long countValidSelections(vector<int>& nums) {
        long long S = 0;
        for (int x : nums) S += x;
        long long ans = 0, L = 0;
        for (int x : nums) {
            if (x != 0) L += x;
            else {
                long long R = S - L;
                if (L == R) ans += 2;
                else if (llabs(L - R) == 1) ans += 1;
            }
        }
        return ans;
    }
};
