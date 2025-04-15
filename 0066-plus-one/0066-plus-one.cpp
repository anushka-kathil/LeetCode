class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(digits[i]==9)
            c++;
        }

        if(c==n)
        {
            digits.resize(n+1);
          for(int i=0;i<n;i++){
            digits[i]=0;
          
          }
          digits[0]=1;
          digits[n]=0;
          return digits;
        }
        
      
        for(int i=n-1;i>=0;i--){
            digits[i]=digits[i]+1;
            if(digits[i]%10!=0)
            break;

            else{
            digits[i]=0;
            // carry=1;    
            continue;
            }
        }
        return digits;
        
    }
};