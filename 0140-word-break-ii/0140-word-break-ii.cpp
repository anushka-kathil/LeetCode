class Solution {
public:
    void dfs(string s, int i, vector<string> &ans, string &words, set<string> st){
        if(i>=s.size()){
            ans.push_back(words);
            return;
        }

        for(int j=i; j<s.size(); j++){
            if(st.count(s.substr(i,j-i+1))){
                int prev_len = words.size();
                words+=s.substr(i,j-i+1)+" ";
                dfs(s,j+1,ans,words,st);
                words.resize(prev_len);
            }

        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string words;
        set<string> st;
        for(auto &w:wordDict){
            st.insert(w);
        }
        dfs(s,0,ans,words,st);
        for(auto &space:ans){
            if (!space.empty()) space.pop_back();
        }
        return ans;
    }
};