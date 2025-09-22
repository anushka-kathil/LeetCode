class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int maxi = INT_MIN;
        for(auto &p:m){
            maxi = max(maxi,p.second);
        }
        int c=0;
        for(auto &i:m){
            if(i.second == maxi) c+=i.second;
        }
        return c;
    }
};