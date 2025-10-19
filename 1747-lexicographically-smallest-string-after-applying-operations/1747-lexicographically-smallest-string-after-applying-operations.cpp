class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        string best = s;
        q.push(s);
        vis.insert(s);
        int n = s.size();
        
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            best = min(best, cur);
            
            string t = cur;
            for (int i = 1; i < n; i += 2)
                t[i] = (t[i] - '0' + a) % 10 + '0';
            if (!vis.count(t)) { vis.insert(t); q.push(t); }
            
            t = cur.substr(n - b) + cur.substr(0, n - b);
            if (!vis.count(t)) { vis.insert(t); q.push(t); }
        }
        return best;
    }
};
