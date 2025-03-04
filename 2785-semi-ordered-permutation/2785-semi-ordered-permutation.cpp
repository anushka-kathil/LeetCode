class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == 1 && nums[n-1] == n){
            return 0;
        }
        int left=-1,right=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            left=i;

            if(nums[i]==n)
            right=i;

            if(left!=-1 && right!=-1)
            {
                break;
            }
        }
        int c=(left-0 + n-1-right);
        if(left > right )
        return c-1;

        return c;
        
    }
};