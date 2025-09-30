class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> newNums;
        int n = nums.size();
        while(n>1){
            newNums.clear();
            for(int i=0; i<n-1; i++){
                newNums.push_back((nums[i]+nums[i+1] )%10);
            }
            nums=newNums;
            n = nums.size();
        }
        return nums[0];
        
    }
};