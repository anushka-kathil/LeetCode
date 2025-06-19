class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1;
        // int mid = s-(e-s)/2;
        while(s<e){
            // if(s>=1 && e<=n-2 && nums[mid] > nums[mid+1] && nums[mid]<nums[mid-1]) return nums[mid];
            int mid = s+(e-s)/2;
            if(nums[mid] > nums[mid+1]) e=mid;
            else s=mid+1;
            
        }
        return s;
    }
};