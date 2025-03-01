class Solution {
public:
    
    int tribonacci(int n) {

        if(n==0 || n==1){
            return n;
         }

        if(n==2)
        return 1;
        
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(1);
        v.push_back(2);

        if(n==3){
            return 0+1+1;
        }

       long long sum=2;
       int pointer=0;

        for(int i=3;i<n;i++){
            sum-=v[pointer];
            pointer++;
           sum+=v[i];
           v.push_back(sum);
        }
        return sum;

      
        
    }
};