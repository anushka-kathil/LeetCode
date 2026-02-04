class Solution {
public:

    vector<tuple<int, int, long long>> splitIntoDecreasingSegments(vector<int>& arr) {
        int size = arr.size();
        vector<tuple<int, int, long long>> segments;

        int start = 0;
        long long currentSum = arr[0];

        for (int idx = 1; idx < size; idx++) {
            if (arr[idx - 1] <= arr[idx]) {
                segments.emplace_back(start, idx - 1, currentSum);
                start = idx;
                currentSum = 0;
            }
            currentSum += arr[idx];
        }

        segments.emplace_back(start, size - 1, currentSum);
        return segments;
    }

    long long maxSumTrionic(vector<int>& arr) {
        int n = arr.size();

        vector<long long> incPrefix(n);
        for (int i = 0; i < n; i++) {
            incPrefix[i] = arr[i];

            if (i > 0 && arr[i - 1] < arr[i]) {
                incPrefix[i] += max(0LL, incPrefix[i - 1]);
            }
        }

        vector<long long> incSuffix(n);
        for (int i = n - 1; i >= 0; i--) {
            incSuffix[i] = arr[i];

            if (i < n - 1 && arr[i] < arr[i + 1]) {
                incSuffix[i] += max(0LL, incSuffix[i + 1]);
            }
        }

        vector<tuple<int, int, long long>> segments = splitIntoDecreasingSegments(arr);

        long long bestAnswer = LLONG_MIN;

        for (auto &[left, right, segSum] : segments) {

            bool validLeft = (left > 0 && arr[left - 1] < arr[left]);
            bool validRight = (right < n - 1 && arr[right] < arr[right + 1]);

            if (validLeft && validRight && left < right) {
                long long total = incPrefix[left - 1] + segSum + incSuffix[right + 1];
                bestAnswer = max(bestAnswer, total);
            }
        }

        return bestAnswer;
    }
};
