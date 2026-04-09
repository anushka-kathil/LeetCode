#include <vector>
#include <cmath>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> total_mult(n, 1);
        
        int B = sqrt(n); 
        vector<vector<long long>> diff(B);
        for(int k = 1; k < B; ++k) diff[k].resize(n + k + 1, 1);

        for (const auto& q : queries) {
            int L = q[0], R = q[1], k = q[2], val = q[3];

            if (k >= B) {
                for (int i = L; i <= R; i += k) {
                    total_mult[i] = (total_mult[i] * val) % MOD;
                }
            } else {
                diff[k][L] = (diff[k][L] * val) % MOD;
                int next_idx = L + ((R - L) / k + 1) * k;
                if (next_idx < n + k) {
                    diff[k][next_idx] = (diff[k][next_idx] * modInverse(val)) % MOD;
                }
            }
        }

        for (int k = 1; k < B; ++k) {
            for (int offset = 0; offset < k; ++offset) {
                long long current_prod = 1;
                for (int i = offset; i < n; i += k) {
                    current_prod = (current_prod * diff[k][i]) % MOD;
                    total_mult[i] = (total_mult[i] * current_prod) % MOD;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            long long final_val = (1LL * nums[i] * total_mult[i]) % MOD;
            result ^= (int)final_val;
        }

        return result;
    }
};