class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n = changed.size();
        vector<int> original;
        if(n%2 == 1) return {};
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[changed[i]]++;
        }

        for(int i=0; i<n; i++){
            if(m[changed[i]] == 0) continue;
            if(m[changed[i]*2] == 0) return {};
            original.push_back(changed[i]);
            m[changed[i]]--;
            m[changed[i]*2]--;
        }
        return original;
    }
};