class Solution {
public:
    vector<int> countBits(int n) {
          vector<int> ans;
          ans.push_back(0);
          for(int i=1; i<=n; i++){
            ans.push_back(__builtin_popcount(i));
          }
         return ans;
    }
};