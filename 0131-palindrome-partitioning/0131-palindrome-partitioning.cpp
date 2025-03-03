class Solution {
public:
   void partition(string s, vector<string>& v, vector<vector<string>>& ans, int k,int n ){
    if(k==n){
        ans.push_back(v);
        return;
    }

    for(int i=k;i<n;i++){
        if(pallindrome(s,k,i)){
            v.push_back(s.substr(k,i-k+1));
            partition(s,v,ans,i+1,n);
            v.pop_back();
        }
    }

   }
   bool pallindrome(string s, int start , int end){
    while(start<end){
        if(s[start]!=s[end]){
           return false;
        }
        start++;
        end--;
        
    }
    return true;

   }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        int n=s.length();
        vector<vector<string>> ans;
        partition(s,v,ans,0,n);
        return ans;
    }
};