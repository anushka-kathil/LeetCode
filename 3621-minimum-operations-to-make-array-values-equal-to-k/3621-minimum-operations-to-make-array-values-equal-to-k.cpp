class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(k>nums[0])
        return -1;
        int n=nums.size();
        int diff=0;

        for(int i=n-1;i>0;i--){
            if(nums[i]==nums[i-1])
            continue;
            else{
                diff++;
            }
        }

        if(k==nums[0])
        return diff;

        else
        return diff+1;
        
    }
};