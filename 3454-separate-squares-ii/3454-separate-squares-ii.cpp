#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long double y;
        int x1, x2;
        int type; // +1 add, -1 remove
        bool operator<(Event const& other) const {
            return y < other.y;
        }
    };

    struct SegTree {
        int n;
        vector<int> cnt;
        vector<long double> len;
        vector<int> xs;

        SegTree(const vector<int>& xs_) : xs(xs_) {
            n = (int)xs.size() - 1;
            cnt.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int idx, int l, int r) {
            if (cnt[idx] > 0) {
                len[idx] = (long double)xs[r + 1] - xs[l];
            } else if (l == r) {
                len[idx] = 0;
            } else {
                len[idx] = len[idx * 2 + 1] + len[idx * 2 + 2];
            }
        }

        void update(int idx, int l, int r, int ql, int qr, int val) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                cnt[idx] += val;
                pull(idx, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(idx * 2 + 1, l, mid, ql, qr, val);
            update(idx * 2 + 2, mid + 1, r, ql, qr, val);
            pull(idx, l, r);
        }

        void addRange(int xL, int xR, int val) { // [xL, xR)
            if (xL >= xR) return;
            int L = lower_bound(xs.begin(), xs.end(), xL) - xs.begin();
            int R = lower_bound(xs.begin(), xs.end(), xR) - xs.begin() - 1;
            if (L <= R) update(0, 0, n - 1, L, R, val);
        }

        long double coveredWidth() const { return len[0]; }
    };

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        vector<Event> events;
        vector<int> xs;
        events.reserve(2 * n);
        xs.reserve(2 * n);

        for (auto &sq : squares) {
            long double y1 = sq[1];
            long double y2 = (long double)sq[1] + sq[2];
            int x1 = sq[0];
            int x2 = sq[0] + sq[2];

            events.push_back({y1, x1, x2, +1});
            events.push_back({y2, x1, x2, -1});
            xs.push_back(x1);
            xs.push_back(x2);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(events.begin(), events.end());

        SegTree st(xs);

        // -------- pass 1: compute total union area --------
        long double total = 0.0L;
        long double prevY = events[0].y;
        int i = 0;

        while (i < (int)events.size()) {
            long double currY = events[i].y;
            long double dy = currY - prevY;
            total += st.coveredWidth() * dy;

            while (i < (int)events.size() && events[i].y == currY) {
                st.addRange(events[i].x1, events[i].x2, events[i].type);
                i++;
            }
            prevY = currY;
        }

        long double half = total / 2.0L;

        // -------- pass 2: locate the Y where area hits half --------
        // reset segtree
        st.cnt.assign(4 * st.n, 0);
        st.len.assign(4 * st.n, 0);

        long double area = 0.0L;
        prevY = events[0].y;
        i = 0;

        while (i < (int)events.size()) {
            long double currY = events[i].y;
            long double dy = currY - prevY;
            long double W = st.coveredWidth();

            if (W > 0 && area + W * dy >= half) {
                long double need = half - area;
                long double ansY = prevY + need / W;
                return (double)ansY;
            }

            area += W * dy;

            while (i < (int)events.size() && events[i].y == currY) {
                st.addRange(events[i].x1, events[i].x2, events[i].type);
                i++;
            }
            prevY = currY;
        }

        // fallback (should never happen)
        return (double)events.back().y;
    }
};
