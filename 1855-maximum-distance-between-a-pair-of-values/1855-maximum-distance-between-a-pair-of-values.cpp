class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0, n = a.size(), m = b.size(), ans = 0;
        while (i < n && j < m) {
            if (a[i] <= b[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};