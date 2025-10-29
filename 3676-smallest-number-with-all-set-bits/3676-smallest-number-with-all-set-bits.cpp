class Solution {
public:
    int smallestNumber(int n) {
        // int s = __builtin_popcount(n);
        int totalBits = (n == 0) ? 1 : floor(log2(n)) + 1;
        int i=n;
        while(true){
            int k = __builtin_popcount(i);
            if(totalBits == k) return i;
            i++;
        }        
    }
};