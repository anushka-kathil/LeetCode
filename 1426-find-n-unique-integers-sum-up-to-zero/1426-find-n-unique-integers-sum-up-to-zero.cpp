class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i=1; i<=n-2; i+=2){
            ans.push_back(-1*i);
            ans.push_back(i);
        }
        if(ans.size() == n) return ans;
        ans.push_back(0);
        return ans;    
    }
};