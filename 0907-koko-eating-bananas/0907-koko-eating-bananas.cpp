class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(),piles.end());
        if(h==n) return maxi;
        int s=1,e=maxi;
        int ans=0;
       
        while(s<=e){
           int mid = s+(e-s)/2;
           long long hours=0;
           for(int p:piles){
            hours+=(p+mid-1)/mid;
           }
           if(hours <= h) {
            ans = mid;
            e = mid-1;}
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};