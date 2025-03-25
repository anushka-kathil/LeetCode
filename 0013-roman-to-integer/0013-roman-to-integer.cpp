class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        map<char,int> m;
        int num=0;
        int i;
        
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        for(i=0;i<n-1;i++){
            if(m[s[i]] >= m[s[i+1]]){
                num+=m[s[i]];
            }
            else{
                num+=m[s[i+1]] - m[s[i]];
                i++;
            }  
        }
        
        if(i==n-1)
        num+=m[s[i]];
        return num;

    }
};