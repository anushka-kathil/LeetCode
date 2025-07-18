class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int currentSum = 0, total = 0;

        for (int num : nums) {
            currentSum += num;
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                total += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }

        return total;
    }
};
