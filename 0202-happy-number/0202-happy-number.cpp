class Solution {
public:
    int digit(int n){
        int ans=0;
        while(n){
            int d=n%10;
            ans+=(d*d);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        if(n==1)
        return true;

       int ans=INT_MAX,c=0;
       unordered_map <int,int> m;
        while(m[n] == 0 && n!=1){
            m[n]++;
            int ans=digit(n);
            n=ans;
        }
        if(n==1)
        return true;

        return false;
             
    }
};