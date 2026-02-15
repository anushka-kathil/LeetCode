class Solution {
public:
    string addBinary(string a, string b) {
        int na=a.length();
        int nb=b.length();

        if(na>nb){
            int numZeroes = na-nb;
            b.insert(0,numZeroes,'0');
        }

        else if(nb>na){
             int numZeroes = nb-na;
             a.insert(0,numZeroes,'0');
        }

        char carry='0';
        string ans="";


        for(int i=max(na,nb);i>=0;i--){
            if(a[i] == '1' && b[i]== '1' && carry=='0'){
                ans+='0';
                carry='1';
            }

            else if(a[i] == '1' && b[i] == '1' && carry=='1'){
                 ans+='1';
                 carry='1';
            }

            else if(a[i] == '1' && b[i]== '0' && carry=='0' || a[i] == '0' && b[i]== '1' && carry=='0'){
                ans+='1';
                carry='0';
            }

              else if(a[i] == '1' && b[i]== '0' && carry=='1' || a[i] == '0' && b[i]== '1' && carry=='1'){
                ans+='0';
                carry='1';
            }

            else if(a[i] == '0' && b[i]== '0' && carry=='0' || a[i] == '0' && b[i]== '0' && carry=='0'){
                ans+='0';
                carry='0';
            }

            else if(a[i] == '0' && b[i]== '0' && carry=='1' || a[i] == '0' && b[i]== '0' && carry=='1'){
                ans+='1';
                carry='0';
            }

        }

        if(carry == '1')
        ans+='1';

        reverse(ans.begin(),ans.end());

        return ans;
    }
};