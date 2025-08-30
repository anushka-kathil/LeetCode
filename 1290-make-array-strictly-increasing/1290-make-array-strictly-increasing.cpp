class Solution {
public:
    int f (int ind, int prev,vector<int>& arr1, vector<int>& arr2, map<pair<int, int>, int>& dp){
        if(ind == arr1.size()){
            return 0;
        }
        if(dp.find({ind,prev}) != dp.end()){
            return dp[{ind,prev}];
        }
        int replace = 1e9, notReplace=1e9;
        int i = upper_bound(arr2.begin(), arr2.end(),prev) - arr2.begin();
        if(i < arr2.size()){
        replace = 1 + f(ind+1, arr2[i], arr1, arr2,dp);
        }

        if(arr1[ind] > prev){
        notReplace = f(ind+1, arr1[ind], arr1, arr2,dp);
        }

        return dp[{ind,prev}] = min(replace,notReplace);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = f(0,-1, arr1, arr2, dp);
        if(ans >= 1e9) return -1;
        return ans;        
    }
};