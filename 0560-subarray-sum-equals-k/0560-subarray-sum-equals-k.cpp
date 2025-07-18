class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            sum=0;
            for(int j=i; j<n; j++){
                // if(nums[j] == )
                sum+=nums[j];
                if(sum==k) cnt++;
            }
        }
        return cnt;

        
    }
};