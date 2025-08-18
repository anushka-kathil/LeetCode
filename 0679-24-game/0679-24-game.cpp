class Solution {
public:
    bool solve(vector<double>& nums){
        if(nums.size()==1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                vector<double> next;
                for(int k=0; k<n; k++){
                    if(k!=i && k!=j) next.push_back(nums[k]);
                }
                vector<double> res;
                double a = nums[i], b=nums[j];
                res = {a+b, a-b, b-a, a*b};
                if(fabs(b) > 1e-6) res.push_back(a/b);
                if(fabs(a) > 1e-6) res.push_back(b/a);
                for(auto& val:res){
                    next.push_back(val);
                    if(solve(next)) return true;
                    next.pop_back();
                }
            }
        }
         return false;
    }
    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};