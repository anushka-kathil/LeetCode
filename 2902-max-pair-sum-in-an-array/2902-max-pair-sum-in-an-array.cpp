class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int n = nums.size();
        int ans = -1;
        for(auto i:nums){
            int t=i, maxDigit=0;
            while(t){
                int dig = t%10;
                maxDigit = max(maxDigit, dig);
                t/=10;
            }
            m[maxDigit].push_back(i);
        }
        // int ans=0;
        for(auto [i,j]:m){
            sort(j.rbegin(),j.rend());
            if(j.size()>=2) ans=max(ans, j[0]+j[1]);
        }   
        return ans;     
    }
};