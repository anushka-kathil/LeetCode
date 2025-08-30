class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi = 1, lastInd =0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            hash[i]=i; // storing index initially
            for(int prev=0; prev<i; prev++){
                if(nums[i] % nums[prev] == 0 && 1+dp[prev] > dp[i]){
                   hash[i] = prev;
                   dp[i] = 1+dp[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastInd = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};