class Solution {
public:
    int jump(vector<int>& nums) {
        int near=0, far=0,jumps=0,index=0,farthest=0;

        while(far < (nums.size()-1)  ){
          farthest=0;
          for(int i=near; i<=far; i++){
            farthest = max(i+nums[i], farthest);
          }
          near=far+1;
          far= farthest;
          jumps++;
        }

        return jumps;        
    }
};