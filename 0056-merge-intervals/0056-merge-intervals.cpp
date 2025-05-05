class Solution {

public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> merged;
        vector<int> v ;
        v.push_back(intervals[0][0]);
         v.push_back(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(v[1] >= intervals[i][0])
            {
                // v.pop_back();
                if(v[1] <= intervals[i][1]){
                v.pop_back();
                v.push_back(intervals[i][1]);
                }
            }
            else{
                merged.push_back(v);
                v.clear();
                v.push_back(intervals[i][0]);
                v.push_back(intervals[i][1]);
            }
        }
        merged.push_back(v);
        return merged;
        
    }
};