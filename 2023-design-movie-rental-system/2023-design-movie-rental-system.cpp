class MovieRentingSystem {
    unordered_map<long long,int> price;
    unordered_map<int,set<pair<int,int>>> avail;
    set<tuple<int,int,int>> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &v: entries) {
            long long key = ((long long)v[0] << 20) | v[1];
            price[key] = v[2];
            avail[v[1]].insert({v[2], v[0]});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (avail.count(movie)) {
            for (auto &p: avail[movie]) {
                if (ans.size() == 5) break;
                ans.push_back(p.second);
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        long long key = ((long long)shop << 20) | movie;
        int p = price[key];
        avail[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie) {
        long long key = ((long long)shop << 20) | movie;
        int p = price[key];
        rented.erase({p, shop, movie});
        avail[movie].insert({p, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto &t: rented) {
            if (ans.size() == 5) break;
            auto [p, s, m] = t;
            ans.push_back({s, m});
        }
        return ans;
    }
};
