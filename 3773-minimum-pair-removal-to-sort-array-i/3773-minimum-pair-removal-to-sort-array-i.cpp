class Solution {
public:
   
    bool sort(vector<int>& nums){
         int n=nums.size();
         for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
            return false;
         }
         return true;
    }
    

    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return 0;
        int sum=INT_MAX;
        int e1=0;
        int c=0;
        while(!sort(nums)){
            sum=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(sum > nums[i]+nums[i+1]){
                sum=nums[i]+nums[i+1];
                e1=i;
            }
            // sum=min(nums[i]+nums[i+1], sum);   
        }
        
        nums[e1]=sum;
        nums.erase(nums.begin()+e1+1);
        n=nums.size();
        c++;
        // for(auto k:nums){
        //     cout<<k<<" ";
        // }
        // cout<<endl;
        }
        return c;
        
    }
};