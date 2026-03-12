class Solution {
public:

    struct DSU {
        vector<int> p, r;

        DSU(int n){
            p.resize(n);
            r.resize(n,0);
            for(int i=0;i<n;i++) p[i]=i;
        }

        int find(int x){
            if(p[x]==x) return x;
            return p[x]=find(p[x]);
        }

        bool unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return false;

            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;

            return true;
        }
    };

    bool check(int n, vector<vector<int>>& edges, int k, long long X){

        DSU dsu(n);
        int used=0;
        int upgrades=0;

        vector<vector<int>> needUpgrade;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<X) return false;
                if(dsu.unite(u,v)) used++;
                else return false;
            }
        }

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            if(must) continue;

            if(s>=X){
                if(dsu.unite(u,v)) used++;
            }
            else if(2LL*s>=X){
                needUpgrade.push_back(e);
            }
        }

        for(auto &e:needUpgrade){
            if(upgrades==k) break;

            int u=e[0],v=e[1];
            if(dsu.unite(u,v)){
                used++;
                upgrades++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long lo=0, hi=2e9, ans=-1;

        while(lo<=hi){

            long long mid=(lo+hi)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;
    }
};