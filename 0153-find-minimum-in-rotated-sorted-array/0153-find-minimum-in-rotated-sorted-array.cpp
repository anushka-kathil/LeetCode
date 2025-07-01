class Solution {
public:
    int findMin(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[0];

        int n = nums.size();
        int s = 0,e = n-1;
        int mid;
        while(s<e){
            int mid = (s+e)/2;
          if(nums[mid] <= nums[e]) e = mid;
          else s = mid+1;
        }
        return nums[s]; 
    }
};