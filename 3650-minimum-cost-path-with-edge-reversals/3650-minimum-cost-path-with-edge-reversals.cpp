#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pii>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);++i)
#define fi first
#define se second

class Solution{
public:
    int minCost(int n, vector<vi>& e){
        if(n<=1) return 0; 
        vector<vpi> g(n);
        for(auto &x:e){
            if((int)x.size()<3) continue; 
            int u=x[0],v=x[1],w=x[2];
            if(u<0 || v<0 || u>=n || v>=n) continue; 
            g[u].pb({v,w});
            g[v].pb({u,2*w});
        }
        vector<ll> d(n,LLONG_MAX);   
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        d[0]=0; pq.push({0,0});
        while(!pq.empty()){
            auto [c,u]=pq.top(); pq.pop();
            if(c > d[u]) continue; 
            if(u == n-1) return (int)c; 
            for(auto &ed:g[u]){
                int v = ed.fi, w = ed.se;
                if(v<0||v>=n) continue; 
                ll nc = d[u]+w;
                if(nc < d[v]){ 
                    d[v]=nc;
                    pq.push({d[v],v});
                }
            }
        }
        if(d[n-1] == LONG_MAX){
            return -1;
        }else{
            return (int)d[n-1];
        }
    }
};