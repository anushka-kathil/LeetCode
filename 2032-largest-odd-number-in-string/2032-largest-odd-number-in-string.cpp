class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string res="";
        for(int i=n-1; i>=0; i--){
            char c = num[i];
            int cc = c-'0';
            if(cc%2){
               res = num.substr(0, i-0+1);
               break;
            }
            else{
                cout<<"AAYA"<<endl;
                continue;
            }

        }
        return res;
    }
};