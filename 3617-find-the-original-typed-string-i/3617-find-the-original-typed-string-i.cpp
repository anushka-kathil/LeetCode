class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<int,int> m;
        int n = word.size();
        int ans = 1;
        for(int i=0; i<n; i++){
            if(word[i] == word[i+1]){
            m[i]++;
            }
        }
        for(auto it:m){
            if(it.second == 0) continue;
            ans+=it.second;
        }
        return ans;
    }
};