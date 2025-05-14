class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";
        for(int i=s.length()-1;i>=0;i--){
           
            if(s[i]==' ' && word.length()>0){
                reverse(word.begin(),word.end());
                ans+=word;
                ans+=" ";
                word="";
            }
            else if(s[i]!=' '){ 
             word+=s[i];}
        }
       
        reverse(word.begin(),word.end());
        ans+=word;
        int i;
        for( i=ans.length()-1;i>=0;i--){
            if(ans[i]!=' '){
                break;
            }
            else continue;
        }
        ans.erase(i+1);
        return ans;
        
    }
};