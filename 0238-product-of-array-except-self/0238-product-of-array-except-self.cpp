class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        long long prod = 1;
        // cout<<prod<<endl;
        int zero=0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) { zero++; continue;}
            prod*=nums[i];
        }
        // cout<<prod<<endl;
        if(zero == n) return nums;
        for(int i=0; i<n; i++){
            if(zero>0 && nums[i]!=0)
            v.push_back(0);
            else if(zero==0 && nums[i]!=0){
            v.push_back(prod/nums[i]);
            }
            else if(nums[i]==0 && zero>1) 
            v.push_back(0);
            else
            v.push_back(prod);
        }
        return v;
    }
};