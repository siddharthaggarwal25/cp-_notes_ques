#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree {
public:
    vector<int> t;

    SegmentTree(int len) {
        t.resize(4 * len);
    }

    void build(vector<int>& a, int ind, int tl, int tr) {
        if (tl == tr) {
            t[ind] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * ind, tl, tm);
        build(a, 2 * ind + 1, tm + 1, tr);
        t[ind] = max(t[2 * ind], t[2 * ind + 1]);
    }

    void update(int ind, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[ind] = val;
            return;
        }
        if (pos < tl || pos > tr) return;

        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * ind, tl, tm, pos, val);
        else
            update(2 * ind + 1, tm + 1, tr, pos, val);

        t[ind] = max(t[2 * ind], t[2 * ind + 1]);
    }

    int query(int ind, int tl, int tr, int k, int l) {
        // No overlap or max value in this segment is less than k
        if (tr < l || t[ind] < k)
            return -1;

        // Leaf node
        if (tl == tr)
            return tl;

        int tm = (tl + tr) / 2;

        // Search left first
        int left = query(2 * ind, tl, tm, k, l);
        if (left != -1)
            return left;

        // If not found in left, search right
        return query(2 * ind + 1, tm + 1, tr, k, l);
    }
};

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;

    SegmentTree seg(n);
    seg.build(a, 1, 0, n - 1);

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            // Update position y to value z
            seg.update(1, 0, n - 1, y, z);
        } else {
            // Query first index ≥ z such that a[i] ≥ y
            int ans = seg.query(1, 0, n - 1, y, z);
            cout << ans << '\n';
        }
    }

    return 0;
}
