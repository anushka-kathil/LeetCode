class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        int min = abs(arr[1]-arr[0]);
        v.push_back({arr[0],arr[1]});
        for(int i=1; i<n-1; i++){
            if(abs(arr[i+1]-arr[i]) == min){
                v.push_back({arr[i],arr[i+1]});
                min = abs(arr[i+1]-arr[i]);
            }
            else if(abs(arr[i+1]-arr[i]) < min){
                v.clear();
                v.push_back({arr[i],arr[i+1]});
                min = abs(arr[i+1]-arr[i]);
            }
        }
        return v;
    }
};