class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> m;
        // sort(word.begin(),word.end()); 
        for(int i=0; i<word.length(); i++){
            m[word[i]]++;
        }
        for(auto it : m){
            m[it.first]--;
            unordered_set<int> s;
            for(auto i : m){
                if(i.second > 0) s.insert(i.second);
            }
            if(s.size() == 1){ 
                // cout<<it.first<<endl;
                return true;
                }
            m[it.first]++;
        }
        return false;

        
    }
};