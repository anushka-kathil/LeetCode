class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            cout<<mid<<endl;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) e = mid -1;
            else s = mid+1;
        }
        return false;
    }
};