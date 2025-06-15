class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // bool flag = false;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[nums[i]] > 1) return nums[i];
        }

        // int s = 0;
        // int e=1;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //       if(nums[i] == nums[j]){
        //         return nums[i];
        //       }
        //     }
        // }
        return -1;

    }
};