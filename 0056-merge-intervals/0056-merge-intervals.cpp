class Solution {

public:
    // static bool cmp(const vector<int>& a, const vector<int>& b) {
    // return a[0] < b[0];
    // }
    static bool cmp(vector<int> val1, vector<int> val2){
        return val1[0] < val2[0];
    }
vector<vector<int>> merge(vector<vector<int>>& intervals) {
   sort(intervals.begin(),intervals.end(), cmp);
        //  cout<<intervals[2][0]<<" "<<intervals[2][1];
        // 
        vector<vector<int>> ans;
        //  int cnt=0;
         ans.push_back(intervals[0]);
         int lastTime=intervals[0][1];
         for(int i=1;i< intervals.size(); i++){
            if (intervals[i][0] <= lastTime) {
                vector<int> v = ans.back();
                ans.pop_back();
                
                v[0]=min(intervals[i][0],v[0]);
                v[1]=max(intervals[i][1],v[1]);
                lastTime = v[1];
                ans.push_back(v);
                // cnt++; // Overlapping interval found
            } else {
                lastTime = intervals[i][1]; // Update the previous end time
                ans.push_back(intervals[i]);
            }
            // if(intervals[i][0] >= lastTime){
            //     cnt++;
            //     lastTime=intervals[i][1];
            // }
         }
        //   for(auto& i:ans){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        //  }

         return ans;
        
    }
};