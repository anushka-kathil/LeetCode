class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0; i<n; i++){
           if(arr[i]%2 == 0) cnt=0;
           else cnt++;
           if(cnt == 3) return true;
        }  
        return false;
    }
};