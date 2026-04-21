class Solution {
public:
    vector<int> p;
    
    int f(int x){
        if(p[x]==x) return x;
        return p[x]=f(p[x]);
    }
    
    void u(int a,int b){
        a=f(a); b=f(b);
        if(a!=b) p[a]=b;
    }
    
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& sw) {
        int n=s.size();
        p.resize(n);
        for(int i=0;i<n;i++) p[i]=i;
        
        for(auto &x:sw) u(x[0],x[1]);
        
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++) mp[f(i)].push_back(i);
        
        int ans=0;
        
        for(auto &it:mp){
            unordered_map<int,int> cnt;
            for(auto i:it.second) cnt[s[i]]++;
            
            for(auto i:it.second){
                if(cnt[t[i]]>0) cnt[t[i]]--;
                else ans++;
            }
        }
        return ans;
    }
};