class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int d = INT_MAX;
        for(int i=0; i<n; i++){
            
            string s = to_string(nums[i]);
            int len = s.size();
            reverse(s.begin(),s.end());
            int k = stoi(s);
            // if(nums[i]%10==0)
            // {
            //     string ss = to_string(k);
            //     reverse(ss.begin(),ss.end());
            //     nums[i]=stoi(ss);
            // }
             
            if(mp.count(nums[i])){
                d=min(d,abs(i-mp[nums[i]]));
            }
            // if(mp.count(nums[i]) && mp.count(k))
            mp[k]=i;
        }
        if(d==INT_MAX) return -1;
        return d;
    }
};