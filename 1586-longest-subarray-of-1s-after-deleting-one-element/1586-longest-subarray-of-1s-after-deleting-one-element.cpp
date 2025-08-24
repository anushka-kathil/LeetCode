class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int z_ind=0,zero=0,ind=0;
        int k=0,ans=0;
        
            while(z_ind < n){
                if(nums[z_ind] == 0 && zero==0) {
                    zero++;
                    ind = z_ind;
                }
                else if(nums[z_ind] == 0 && zero==1){
                    z_ind = ind;
                    zero=0;
                    ans = max(ans,k);
                    k=0;
                }
                else if(nums[z_ind]==1){
                   k++;
                }
                z_ind++;            
        }
        if(k==n) return k-1;
        return ans=max(ans,k);

        
    }
};