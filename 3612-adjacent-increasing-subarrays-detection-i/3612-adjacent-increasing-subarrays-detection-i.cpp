#include <vector>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (2 * k > n) return false;
        vector<int> lenInc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) lenInc[i] = lenInc[i-1] + 1;
            else lenInc[i] = 1;
        }
        for (int i = 0; i + 2 * k - 1 < n; i++) {
            int end1 = i + k - 1;
            int end2 = i + 2 * k - 1;
            if (lenInc[end1] >= k && lenInc[end2] >= k) return true;
        }
        return false;
    }
};
