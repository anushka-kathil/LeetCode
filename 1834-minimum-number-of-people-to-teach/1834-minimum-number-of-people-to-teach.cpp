class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knows(m+1);
        for(int i=0; i<m; i++){
            for(int lang : languages[i]){
                knows[i+1].insert(lang);
            }
        }   
        unordered_set<int> needTeach;
        for(auto &f : friendships){
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for(int lang : knows[u]){
                if(knows[v].count(lang)){
                    canCommunicate = true;
                    break;
                }
            }
            if(!canCommunicate){
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        if(needTeach.empty()) return 0;
        vector<int> count(n+1, 0);
        for(int person : needTeach){
            for(int lang : knows[person]){
                count[lang]++;
            }
        }
        int maxKnown = 0;
        for(int lang=1; lang<=n; lang++){
            maxKnown = max(maxKnown, count[lang]);
        }
        return (int)needTeach.size() - maxKnown;
    }
};
