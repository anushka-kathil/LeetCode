class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n = x;
        int sum=0;
        while(n){
            int d = n%10;
            sum+=d;
            n/=10;
        }
        if(x%sum == 0) return sum;
        else return -1;
    }
};