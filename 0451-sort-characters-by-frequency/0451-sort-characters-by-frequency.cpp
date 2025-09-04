class Solution {
public:
    string frequencySort(string s) {
        // string ns = s;
        // for (char &c : ns) {
        //     c = tolower(c);
        // }
        map<char,int> m;
        int n = s.size();
        for(int i=0; i<n;i++){
            // char c = tolower(c);
            m[s[i]]++;
        }

         vector<pair<char,int>> vec(m.begin(), m.end());
          sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        
        string ans="";
        for(auto &p : vec){
            ans.append(p.second, p.first);
        }
        
        return ans;
    
    }
};