class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int i=1;
        int j=0;
        vector<int> v;
        while(j<n && v.size()<k){
            if(arr[j] == i){
                j++;
                i++;
            }
            else if(arr[j] != i){
                v.push_back(i);
                i++;
            }
        }
        while(v.size()<k){
             v.push_back(i);
                i++;
        }
        
        return v[k-1];
        
    }
};