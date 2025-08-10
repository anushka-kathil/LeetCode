class Solution {
private:
    long long digit(long long n) {
        long long cnt = 0;
        while (n) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    long long sum(long long n) {
        long long s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    bool reorderedPowerOf2(long long n) {
        long long no_of_digits = digit(n);
        long long sum_of_digits = sum(n);
        long long s = 1;
        while (digit(s) <= no_of_digits) {
            if (digit(s) == no_of_digits) {
                if (sum(s) == sum_of_digits) { 
                    string a = to_string(s);
                    string b = to_string(n);
                    sort(a.begin(), a.end());
                    sort(b.begin(), b.end());
                    if (a == b)
                        return true;
                }
            }
            s *= 2;
        }
        return false;
    }
};
