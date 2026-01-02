class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int nw = n/2;
        map<int,bool> m;
        for(int i=0; i<n; i++){
            if(m[nums[i]] == false){
                int sum = count(nums.begin(),nums.end(),nums[i]);
                if(sum == nw) return nums[i];
                m[nums[i]] == true;
            }
        }
        return 0;
    }
};