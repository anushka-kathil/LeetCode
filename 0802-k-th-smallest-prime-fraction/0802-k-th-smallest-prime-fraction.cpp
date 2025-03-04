class Solution {
   
public:
 static bool cmp(const pair<double, pair<int, int>>& a, const pair<double, pair<int, int>>& b){
    return a.first < b.first;
   }
  

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double,pair<int,int>>> v;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){ 
                v.push_back(make_pair((double)arr[i]/arr[j], make_pair(arr[i],arr[j])));
            }
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> v1;
                v1.push_back(v[k-1].second.first);
                v1.push_back(v[k-1].second.second);
                return v1;
        
        
        // return 0;
        
    }
};