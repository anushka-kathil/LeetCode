class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m = version2.size();
         string s1="",s2="";
         int ans=0;
         int ind1=0,ind2=0;
         for(int i=0;i<max(n,m); i++){
            while(ind1<n && version1[ind1] != '.'){
                s1+=version1[ind1];
                ind1++;
            }
            while(ind2<m && version2[ind2] != '.' ){
                s2+=version2[ind2];
                ind2++;
            }
            if(s1=="") s1='0';
            if(s2=="") s2='0';
            if(stoi(s1) > stoi(s2)){
                ans = 1; 
                break;}
            else if(stoi(s1) < stoi(s2)){ 
            ans = -1;
            break;
            }
            else{ 
            ans=0;}
            i=max(ind1,ind2);
                s1="";
                s2="";
                ind1++;
                ind2++;
        }

        if(ans != 0) return ans;
        if(s1=="") s1='0';
        if(s2=="") s2='0';

        if(stoi(s1) > stoi(s2)) ans = 1;
        else if(stoi(s1) < stoi(s2)) ans = -1;
        else ans=0;
        return ans;
        
    }
};