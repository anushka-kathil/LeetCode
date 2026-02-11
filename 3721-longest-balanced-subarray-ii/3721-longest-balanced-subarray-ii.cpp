#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    class SegmentTree {
        int n;
        vector<int> min_val;
        vector<int> max_val;
        vector<int> lazy;

    public:
        SegmentTree(int size) {
            n = size;
            min_val.assign(4 * n, 1e9);
            max_val.assign(4 * n, -1e9);
            lazy.assign(4 * n, 0);
        }

        void push(int node) {
            if (lazy[node] != 0) {
                lazy[2 * node] += lazy[node];
                min_val[2 * node] += lazy[node];
                max_val[2 * node] += lazy[node];

                lazy[2 * node + 1] += lazy[node];
                min_val[2 * node + 1] += lazy[node];
                max_val[2 * node + 1] += lazy[node];

                lazy[node] = 0;
            }
        }

        void set(int node, int start, int end, int idx, int val) {
            if (start == end) {
                min_val[node] = val;
                max_val[node] = val;
                lazy[node] = 0;
                return;
            }
            push(node);
            int mid = (start + end) / 2;
            if (idx <= mid) set(2 * node, start, mid, idx, val);
            else set(2 * node + 1, mid + 1, end, idx, val);

            min_val[node] = min(min_val[2 * node], min_val[2 * node + 1]);
            max_val[node] = max(max_val[2 * node], max_val[2 * node + 1]);
        }

        void update(int node, int start, int end, int l, int r, int val) {
            if (l > end || r < start) return;
            if (l <= start && end <= r) {
                min_val[node] += val;
                max_val[node] += val;
                lazy[node] += val;
                return;
            }
            push(node);
            int mid = (start + end) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid + 1, end, l, r, val);

            min_val[node] = min(min_val[2 * node], min_val[2 * node + 1]);
            max_val[node] = max(max_val[2 * node], max_val[2 * node + 1]);
        }

        int query_first_zero(int node, int start, int end) {
            if (min_val[node] > 0 || max_val[node] < 0) return -1;

            if (start == end) {
                return (min_val[node] == 0) ? start : -1;
            }

            push(node);
            int mid = (start + end) / 2;

            int res = query_first_zero(2 * node, start, mid);
            if (res != -1) return res;

            return query_first_zero(2 * node + 1, mid + 1, end);
        }
    };

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(n + 1);

        vector<int> last_pos(100001, -1);

        int max_len = 0;

        st.set(1, 0, n, 0, 0);

        for (int j = 0; j < n; ++j) {
            int val = nums[j];

            int change = (val % 2 == 0) ? 1 : -1;
            int prev = last_pos[val];

            st.update(1, 0, n, prev + 1, j, change);

            st.set(1, 0, n, j + 1, 0);

            int i = st.query_first_zero(1, 0, n);

            if (i != -1) {
                max_len = max(max_len, j - i + 1);
            }

            last_pos[val] = j;
        }

        return max_len;
    }
};
