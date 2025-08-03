class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int l=1,r=num/2;

        while(l<=r){
            int mid = l+(r-l)/2;
            long long square = 1LL * mid * mid;
            if(square == num) return true;
            else if(square > num) r = mid-1;
            else l = mid+1;
        }
        return false;
    }
};