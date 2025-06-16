#include <bits/stdc++.h>
using namespace std;
#define int long long 

class SegmentTree
{
public:
    vector<int> t, isLazy, unpropvalue;

    SegmentTree(int len)
    {
        t.resize(4 * len, 0);
        isLazy.resize(4 * len, 0);
        unpropvalue.resize(4 * len, 0);
    }

    void apply(int ind, int tl, int tr, int value)
    {
        if (tl != tr)
        {
            isLazy[ind] = 1;
            unpropvalue[ind] += value;
        }
        t[ind] = t[ind] + value ; 
    }

    void push_down(int ind, int tl, int tr)
    {
        if (!isLazy[ind]) return;
        isLazy[ind] = 0;
        int tm = (tl + tr) / 2;
        apply(2 * ind, tl, tm, unpropvalue[ind]);
        apply(2 * ind + 1, tm + 1, tr, unpropvalue[ind]);
        unpropvalue[ind] =  0   ;
    }

    void update(int ind, int tl, int tr, int l, int r, int v)
    {

        if (tl > r || tr < l)
            return;
        if (l <= tl && tr <= r)
        {
            apply(ind, tl, tr, v);
            return;
        }

        push_down(ind, tl, tr);

        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, l, r, v);
        update(2 * ind + 1, tm + 1, tr, l, r, v);
        t[ind] = min(t[2 * ind], t[2 * ind + 1]);
    }

    int query(int ind, int tl, int tr, int l, int r)
    {
        if (l > tr || r < tl)
            return 1e16;
        if (l <= tl && tr <= r)
            return t[ind];

        int tm = (tl + tr) / 2;
        push_down(ind, tl, tr);
        int leftans = query(2 * ind, tl, tm, l, r);
        int rightans = query(2 * ind + 1, tm + 1, tr, l, r);
        return min(leftans, rightans);
    }
};

int32_t main()
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
            seg.update(1, 0, n - 1, l, r-1, v);
            // update
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int ans = seg.query(1, 0, n - 1, l, r-1);
            cout << ans << endl;
            // min in range
        }
    }

    return 0;
}