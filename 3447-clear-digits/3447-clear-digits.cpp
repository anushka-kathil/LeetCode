class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int n=s.length();
       int count=0;
        for(int i=n-1;i>=0;i--)
        {

            if(count == 0 && s[i] >= 97 && s[i] <= 122)
            ans+=s[i];

            else if(s[i] >= 48 && s[i] <= 57){
                count++;
                // cout<<"**"<<endl;
                // cout<<s[i]<<" "<<endl;
            }

            else{
                count--;
                // continue;
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};