class Solution {
public:
    
    long long maxHeight(long long time, int t) {
        long long l = 0, r = 1e6;
        
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long req = (long long)t * mid * (mid + 1) / 2;
            
            if (req <= time) l = mid + 1;
            else r = mid - 1;
        }
        
        return r;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0, right = 1e18;
        long long ans = right;
        
        while (left <= right) {
            
            long long mid = (left + right) / 2;
            long long total = 0;
            
            for (int t : workerTimes) {
                total += maxHeight(mid, t);
                if (total >= mountainHeight) break;
            }
            
            if (total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};