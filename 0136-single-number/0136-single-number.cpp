class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n=;
        int x=0;
        for(int i=0;i<nums.size();i++){
          x= x^nums[i];
        }
        return x;
        
    }
};