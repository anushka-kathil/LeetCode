class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int c = INT_MAX;
        for(int i=1; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                c=min(nums[i]+nums[j],c);
            }
        }
        return sum + c;
    }
};