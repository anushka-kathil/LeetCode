class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        for(int i=0; nums.size()>1; i++){
            if(i == nums.size()) i=0;
            if(i%2 == 0){
            int mini = min(nums[i], nums[i+1]);
            nums[i]=mini;
            nums.erase(nums.begin() + i+1);
            if(nums.size() == 1) {
                break;
            }
            }
            else{
            int maxi = max(nums[i], nums[i+1]);
            nums[i]=maxi;
            nums.erase(nums.begin() + i+1);
            if(nums.size() == 1) {
                break;
            }

            }
        }
        return nums[0];   
    }
};