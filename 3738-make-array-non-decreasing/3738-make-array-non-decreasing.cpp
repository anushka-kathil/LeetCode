class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int k=0;
        int prev=-1;
        for(int i=0; i<nums.size();i++){
            if(nums[i] >= prev) {
                k++;
                prev=nums[i];
                }
        }
        return k;
    }
};