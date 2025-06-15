#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree
{
public:
    vector<int> t;

    SegmentTree(int len)
    {
        t.resize(4 * len);
    }

    void build(vector<int> &a, int ind, int tl, int tr)
    {
        if (tl == tr)
        {
            t[ind] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * ind, tl, tm);
        build(a, 2 * ind + 1, tm + 1, tr);
        t[ind] = t[2 * ind] + t[2 * ind + 1];
    }

    void update(int ind, int tl, int tr, int position)
    {
        if (tl == position && tr == position)
        {
            t[ind] = t[ind] ^ 1;
            return;
        }
        if (position > tr || position < tl)
            return;

        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, position);
        update(2 * ind + 1, tm + 1, tr, position);
        t[ind] = t[2 * ind] + t[2 * ind + 1];
    }
    int query(int ind, int tl, int tr, int k)
    {
        if (tl == tr)
            return tl;
        int tm = (tl + tr) / 2;
        if (t[2 * ind] >= k)
        {
             return query(2 * ind, tl, tm, k);
        }
        else
        {
           return  query(2 * ind + 1, tm + 1, tr, k - t[2 * ind]);
        }
    }
};
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    SegmentTree seg(n);
    seg.build(v, 1, 0, n - 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            seg.update(1, 0, n - 1, b);
        }
        else
        {
            int ans = seg.query(1, 0, n - 1, b + 1);
            cout << ans << endl;
        }
    }

    return 0;
}