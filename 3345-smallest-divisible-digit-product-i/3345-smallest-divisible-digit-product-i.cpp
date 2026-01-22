class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(true){
            int k = i;
            int p=1;
            while(k){
                p*=(k%10);
                k/=10;
            }
            if(p%t == 0) return i;
            i++;
        }
        return 0;
        
    }
};