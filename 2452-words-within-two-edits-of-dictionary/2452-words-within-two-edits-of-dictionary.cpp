class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        
        for(auto &a:q){
            for(auto &b:d){
                int c=0;
                for(int i=0;i<a.size();i++){
                    if(a[i]!=b[i]) c++;
                    if(c>2) break;
                }
                if(c<=2){
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};