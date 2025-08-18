class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        
        while (start < end) {
            int mid = start + (end - start) / 2;  
            long long sum = 0;
            for (int num : nums) {
                sum += ceil((double)num / mid);
            }
            if (sum > threshold) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};
