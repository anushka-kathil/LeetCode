class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m, curr;
        string s ="balloon";
        for(auto ch:text){
            curr[ch]++;
        }

        int b = curr['b'];
        int a = curr['a'];
        int n = curr['n'];
        int l = curr['l'];
        int o = curr['o'];
        // cout<<b<<" "<<a<<" "<<l<<" "<<o<<" "<<n;
        int sing=INT_MAX;
        int mult=INT_MAX;
        if(b>0 && a>0 && n>0 && l>0 && o>0){
            sing =min(sing, min(b, min(a,n))) ;
            mult = min(mult, min(l,o));
        }
        else{ return 0;}

         
        return min(sing, mult/2);
        

     

    }
};