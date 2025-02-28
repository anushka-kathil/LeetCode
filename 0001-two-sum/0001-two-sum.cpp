class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<n;i++){
            // v.push_back(i);
            int more = target - nums[i];
             
            if(m.find(more) != m.end()){
                v.push_back(m[more]);
                
                v.push_back(i);
                break;
                
            }
            m[nums[i]]=i;
           
        }
        return v;
        
    }
};