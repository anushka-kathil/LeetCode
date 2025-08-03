class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy = score;
        vector<string> ans;
         int n = score.size();
        if(n==1) return {"Gold Medal"};
        if(n==2){
            if(score[0] > score[1]) {
                ans.push_back("Gold Medal");
                ans.push_back("Silver Medal");
                return ans;
            }
            else{
                ans.push_back("Silver Medal");
                 ans.push_back("Gold Medal");
                  return ans;
            }
        }
        sort(copy.begin(),copy.end());
        unordered_map<int,string> m;
       
        m[copy[n-1]] = "Gold Medal";
        m[copy[n-2]] = "Silver Medal";
        m[copy[n-3]] = "Bronze Medal";
        int cnt=4;
        for(int i=n-4; i>=0; i--){
            m[copy[i]] = to_string(cnt);
            cnt++;
        }
        for(int i=0; i<n; i++){
            if(m.find(score[i]) != m.end()) ans.push_back(m[score[i]]);
            else ans.push_back(m[score[i]]);
        }
        return ans;
        
    }
};