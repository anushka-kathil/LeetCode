class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // map<char, int> m={,-1};
        int n= s.length();
        if(s==" ")
        return 1;
        else if(n==1)
        return 1;
        int hash[255];
        memset(hash, -1, sizeof(hash));
        
        int l=0,r=0,index=0;
        int len=0,maxLen=0;
         
        while(r<n){
            if(hash[s[index]] == -1){
                len = r-l+1;
                maxLen=max(maxLen , len);
                hash[s[index]]=index;
                r++;
            }
            else if(l <= hash[s[index]]){
                l=hash[s[index]] + 1;
                hash[s[index]]= index;
                len = r-l+1;
                maxLen=max(maxLen , len);
                r++;
            }
            else{
                hash[s[index]]= index;
                len = r-l+1;
                maxLen=max(maxLen , len);
                r++;
            }
            index++;
        }
        return maxLen;
    }
};