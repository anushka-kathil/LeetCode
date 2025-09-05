class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int> seen;
        vector<int> uniqueOrder;

        for (int x : nums) {
            if (!seen.count(x)) {
                seen.insert(x);
                uniqueOrder.push_back(x);
            }
        }
        if(uniqueOrder.size()<3) return *max_element(uniqueOrder.begin(),uniqueOrder.end());
        sort(uniqueOrder.rbegin(),uniqueOrder.rend());
        
        return uniqueOrder[2];
    
    }
};