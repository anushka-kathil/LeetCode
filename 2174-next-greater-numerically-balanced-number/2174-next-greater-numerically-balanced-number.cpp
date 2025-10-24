#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        while (!isBalanced(++n));
        return n;
    }

private:
    bool isBalanced(int x) {
        vector<int> cnt(10, 0);
        while (x > 0) {
            int d = x % 10;
            if (d == 0) return false;
            ++cnt[d];
            x /= 10;
        }
        for (int d = 1; d <= 9; ++d)
            if (cnt[d] && cnt[d] != d) return false;
        return true;
    }
};
