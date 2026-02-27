class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.length();
        long long c = 0;
        
        for (char ch : s) {
            if (ch == '0') c++;
        }
        
        if (c == 0) return 0;
        
        for (long long m = 1; m <= n + 5; ++m) {
            long long total_flips = m * (long long)k;
            
            if (total_flips < c) continue;
            
            if (total_flips % 2 != c % 2) continue;
            
            long long o_max = (m % 2 != 0) ? m : m - 1;
            long long e_max = (m % 2 == 0) ? m : m - 1;
            
            long long max_possible_flips = c * o_max + (n - c) * e_max;
            
            if (total_flips <= max_possible_flips) {
                return m;
            }
        }
        
        return -1;
    }
};