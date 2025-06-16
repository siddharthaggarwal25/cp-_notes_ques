#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    vector<int> t, isLazy, unval;
    SegmentTree(int len)
    {
        t.resize(4 * len, 1);
        isLazy.resize(4 * len, 0);
        unval.resize(4 * len, 1);
    }

    void apply(int ind, int tl, int tr, int val)
    {
        if (tl != tr)
        {
            isLazy[ind] = 1;
            unval[ind] = unval[ind] * val;
        }
        t[ind] = t[ind] * val;
    }

    void push_down(int ind, int tl, int tr)
    {
        if (!isLazy[ind])
            return;
        isLazy[ind] = 0;
        int tm = (tl + tr) / 2;
        apply(2 * ind, tl, tm, unval[ind]);
        apply(2 * ind + 1, tm + 1, tr, unval[ind]);
        unval[ind] = 1;
    }
    int query(int ind, int tl, int tr, int l, int r)
    {
        if (tl > r || l > tr)
            return 0;
        if (l <= tl && tr <= r)
            return t[ind];
        push_down(ind, tl, tr);
        int tm = (tl + tr) / 2;
        int leftans = query(2 * ind, tl, tm, l, r);
        int rightans = query(2 * ind + 1, tm + 1, tr, l, r);
        return leftans + rightans;
    }

    void update(int ind, int tl, int tr, int l, int r, int val)
    {
        if (tl > r || l > tr)
            return;
        if (l <= tl && tr <= r)
        {
            apply(ind, tl, tr, val);
            return;
        }

        push_down(ind, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, l, r, val);
        update(2 * ind + 1, tm + 1, tr, l, r, val);
        t[ind] = t[2 * ind] + t[2 * ind + 1];
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    SegmentTree seg(n);
    while (m--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            seg.update(1, 0, n - 1, l, r - 1, v);
        }
        else
        {
            int l, r;
            cout << seg.query(1, 0, n - 1, l, r - 1) << endl;
        }
    }
    return 0;
}