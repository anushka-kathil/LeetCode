class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int,int> m;
        int c=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>=2){
                c++;
                break;
            }
        }
        if(c!=0)
        return true;

        return false;
        
    }
};