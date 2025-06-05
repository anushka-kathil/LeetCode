class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
         int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j= i+1;
            int k=n-1;
           
            while(j<k){
                int sum = nums[i] + nums[j]+nums[k];
              if(abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if(sum == target){
                    return target;
                    
                }

                else if(sum > target){
                    k--;
                }
                else {
                j++;}

                // if(a)

                // ans = min(ans,abs(target - sum));
                

                // while(j<k && nums[j] == nums[j-1]) j++;
                // while(j<k && nums[k] == nums[k+1]) k--;
            }
        }
        return closestSum;
    }
};