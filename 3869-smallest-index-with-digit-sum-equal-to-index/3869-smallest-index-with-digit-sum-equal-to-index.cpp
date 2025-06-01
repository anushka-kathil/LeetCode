class Solution {
public:
    int sumOfDigit(int k){
        int sum=0;
        while(k){
          sum+=k%10;
          k/=10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i == nums[i] && i<10)
            {
                return i;
            }
            else if(i == sumOfDigit(nums[i])){
                return i;
            }
        }
        return -1;
    }
};