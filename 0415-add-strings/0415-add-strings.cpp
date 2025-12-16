class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j = num2.size()-1;
        int carry = 0,sum=0;
        string ans="";
        while(i>=0 || j>=0 || carry>0){
            int d1=0,d2=0;
            if(i>=0)
            d1 = num1[i] - '0';

            if(j>=0)
            d2 = num2[j] - '0';

            sum=(d1+d2+carry)%10;
            carry=(d1+d2+carry)/10;
            ans += sum+'0';
            
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};