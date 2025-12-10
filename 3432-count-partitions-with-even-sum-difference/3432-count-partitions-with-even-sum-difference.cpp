class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int cnt=0, left=0, right=0;
        for(int i=0; i<n-1; i++){
             left+= nums[i];
             right = sum - left;
             if(abs(left-right)%2==0) cnt++;
        }
        return cnt; 
    }
};