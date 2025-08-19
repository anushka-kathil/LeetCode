class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long c=0, cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                c++;
                cnt+=c;
            }
            else{
                c=0;
            }
        }
        return cnt; 
    }
};