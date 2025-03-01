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

        // int s=0,s1=1,s2=1;
        // int sum=s+s1+s2;
        
        // for(int i=3;i<)

        // while(n>2){


        // }
       
        // return n;
        

        // return tribonacci (n-1 + n-2 + n-3);
        
    }
};