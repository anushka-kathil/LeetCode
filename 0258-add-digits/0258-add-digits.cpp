class Solution {
public:
    int sum(int num){
        int s=0;
        while(num){
            int digit = num%10;
            s+=digit;
            num = num/10;
        }
        return s;
    }
    
    int addDigits(int num) {
        while(num){
            num = sum(num);
            if(num<10){
                break;
            }
        }
        return num;
        
    }
};