class Solution {

public:
    // static bool cmp(const vector<int>& a, const vector<int>& b) {
    // return a[0] < b[0];
    // }
vector<vector<int>> merge(vector<vector<int>>& interval) {
 int n = interval.size();
 vector<vector<int>> ans;
sort(interval.begin(),interval.end());
if(n == 0) return {};
vector<int> v;
int last=interval[0][1];
int small = interval[0][0];
v.push_back(small);
v.push_back(last);
for(int i = 1; i<n;i++){
if(last >= interval[i][0]) {
v.clear();
last = max(last,interval[i][1]);
small = min(small,interval[i][0]);
v.push_back(small);
v.push_back(last);
}
else {ans.push_back(v);
v.clear();

small = interval[i][0];
last = interval[i][1];

v.push_back(small);
v.push_back(last);
}
}
if(v.empty() == false) ans.push_back(v);
if(ans.empty() == true) {
    // v.push_back(small);
    // v.push_back(last);
    ans.push_back(v);
}

return ans;
        
    }
};