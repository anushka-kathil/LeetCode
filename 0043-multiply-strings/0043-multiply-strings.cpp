class Solution {
public:
    string multiply(string num1, string num2) {
    
        int len1=num1.length();
        int len2=num2.length();
         if (num1 == "0" || num2 == "0") return "0";
         


        vector<int> v(len1+len2,0);
        for(int i=len1-1; i>=0; i--){
            for(int j=len2-1; j>=0; j--){
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int sum = prod + v[i+j+1];
                v[i+j+1] = sum % 10;
                v[i+j] += sum/10;
            }
        }
        
        string ans="";
        for(auto i:v){
            if(ans.empty() && i==0) continue;
            ans+=i+'0';
        }

        return ans;    
    }
};