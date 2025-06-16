class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int index;
        // int i=0;
        sort(nums.begin(),nums.end());
        // while(i<n){
        //     if(nums[i] & (1<<i))
        //     i++;
        //     else
        //     break;

        // }
        for(int i=0;i<n;i++){
            if(i!=nums[i])
            {
              index=i;
              break;
            }
        }
        return index;
        
    }
};