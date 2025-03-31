class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        int count = 0;
        if(n==1) ans = strs[0];
        for(int i = 0 ; i < strs[0].length() ; i++)
        {
            count = 0;
            for(int j = 0; j<n-1; j++ )
            {
                // cout<<strs[j][i]<<" "<<strs[j+1][i]<<" ";
                // cout<<endl;
                if(strs[j][i]==strs[j+1][i]) count++;
                if(count==n-1) ans+=strs[j][i];
            }
            if(count!=n-1) break;
            
        }
        return ans;
    }
};