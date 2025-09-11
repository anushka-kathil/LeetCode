class Solution {
public:
    static bool cmp(char a, char b){
        return a-0 > b-0;
    }

    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char,int> m ;
        m['A']='A'; m['E']='E'; m['I']='I'; m['O']='O'; m['U']='U';
        m['a']='a'; m['e']='e'; m['i']='i'; m['o']='o'; m['u']='u';
        string t="";
        vector<int> v;
        for(int i=0; i<n; i++){
            if(m.find(s[i]) != m.end()){
                v.push_back(m[s[i]]);
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(int i=0; i<n; i++){
            if(m.find(s[i]) == m.end()) t+=s[i];
            else{
               t+=v.back();
               v.pop_back();
            }
        }
        return t;
        
    }
};