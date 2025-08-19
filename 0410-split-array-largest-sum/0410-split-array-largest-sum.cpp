class Solution {
public:
    bool solve(vector<int>& nums, int k, int mid){
        int curr=0, c=1;
        for(int i=0; i<nums.size(); i++){
            if(curr + nums[i] > mid){
                c++;
                curr=nums[i];
                if(c>k) return false;
            }
            else{
                curr+=nums[i];
            }
        }
        return true;

    }
    int splitArray(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(), nums.end());
        long long r = accumulate(nums.begin(), nums.end(),0LL);
        long long ans=r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(solve(nums,k,mid)){
                ans = mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }
        }

        return ans;

        
    }
};