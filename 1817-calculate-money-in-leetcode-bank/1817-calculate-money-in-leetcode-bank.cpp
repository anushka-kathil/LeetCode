class Solution {
public:
    int totalMoney(int n) {
        long long weeks = n / 7;
        long long days = n % 7;

        long long sum = 28 * weeks + (weeks * (weeks - 1) / 2) * 7;
        sum += days * (days + 1) / 2 + days * weeks;

        return (int)sum;
    }
};