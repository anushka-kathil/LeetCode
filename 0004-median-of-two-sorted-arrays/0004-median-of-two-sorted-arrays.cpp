class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        int n3 = nums1.size();
        
        if (n3 % 2 != 0) {
            return nums1[n3 / 2];
        } else {
            int mid1 = n3 / 2 - 1;
            int mid2 = n3 / 2;
            return (nums1[mid1] + nums1[mid2]) / 2.0;
        }
    }
};