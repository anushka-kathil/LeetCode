class Solution {
private: 
   void isPrime(vector<bool>& v, int n){
        for(int i=2; i<n; i++){
            if(v[i] == true){
            for(int j=i*2; j<n; j+=i){
                v[j] = false;
            }
          }
        }
    }

public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int cnt=0;
        vector<bool> v(n,true);
        isPrime(v,n);
        for(int i=2; i<n; i++){
            if(v[i]){ cnt++;}
        }
        return cnt;
    }
};