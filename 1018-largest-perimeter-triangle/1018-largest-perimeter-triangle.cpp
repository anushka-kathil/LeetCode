class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        long long n = nums.size();
        int perimeter=0;
        sort(nums.begin(),nums.end());
        for(int i = n-1; i>=2 ; i--){
            long long a = nums[i];
            long long b = nums[i-1];
            long long c = nums[i-2];
            if(b+c > a){
                perimeter = a+b+c;
                return perimeter;
            }
        }
        return perimeter;
    }
};