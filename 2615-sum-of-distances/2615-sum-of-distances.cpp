class Solution {
public:
    vector<long long> distance(vector<int>& a) {
        int n = a.size();
        unordered_map<int, vector<int>> m;
        for(int i=0;i<n;i++) m[a[i]].push_back(i);

        vector<long long> res(n);

        for(auto &p:m){
            auto &v = p.second;
            int k = v.size();

            vector<long long> pre(k+1);
            for(int i=0;i<k;i++) pre[i+1]=pre[i]+v[i];

            for(int i=0;i<k;i++){
                long long left = 1LL*v[i]*i - pre[i];
                long long right = (pre[k]-pre[i+1]) - 1LL*v[i]*(k-i-1);
                res[v[i]] = left + right;
            }
        }
        return res;
    }
};