class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        // cout<<s[0];
        string ns="";
        string in = "1";

        for(int i=1; i<n; i++){
            reverse(in.begin(),in.end());
            string prev = s;
            s = prev + '1' + in;
            prev = s;
            // cout<<s<<endl;
            in="";
            for(char c:s){
                if(c=='0') in+="1";
                else in+="0";
            }

        }
        return s[k-1];

    }
};