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
        // int arr[5]={}
        // for(int i=0;i<255;i++){
        //     hash[i]=-1;
        // }
        
        int l=0,r=0,index=0;
        int len=0,maxLen=0;
        // cout<<"->"<<hash[s[index]]<<endl;
        // cout<<"->"<<hash['i']<<endl;
         
        

        while(r<n){
            if(hash[s[index]] == -1){
                // cout<<"*"<<endl;
                len = r-l+1;
                maxLen=max(maxLen , len);
                hash[s[index]]=index;
                r++;
            }
            else if(l <= hash[s[index]]){
                //  cout<<"&"<<endl;
                l=hash[s[index]] + 1;
                hash[s[index]]= index;
                len = r-l+1;
                maxLen=max(maxLen , len);
                r++;
            }
            else{
                //  cout<<"#"<<endl;
                hash[s[index]]= index;
                len = r-l+1;
                maxLen=max(maxLen , len);
                r++;
            }
            index++;
            //  cout<<"**"<<endl;
        }
        return maxLen;
    }
};