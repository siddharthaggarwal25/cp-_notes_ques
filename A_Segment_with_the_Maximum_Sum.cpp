#include <bits/stdc++.h>
using namespace std;
#define int long long

struct data
{
    int sum, pre, suf, best;
    data()
    {
        sum = pre = suf = best = 0;
    }
    data(int val)
    {
        sum = val;
        pre = max(0LL, val);
        suf = max(0LL, val);
        best = max(0LL, val);
    }
};

class SegmentTree
{
public:
    vector<data> t;

    SegmentTree(int len)
    {
        t.resize(4 * len);
    }

    void build(vector<int> &a, int ind, int tl, int tr)
    {
        if (tl == tr)
        {
            t[ind] = data(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * ind, tl, tm);
        build(a, 2 * ind + 1, tm + 1, tr);
        t[ind] = calc(t[2 * ind], t[2 * ind + 1]);
    }

    void update(int ind, int tl, int tr, int position, int value)
    {
        if (tl == position && tr == position)
        {
            t[ind] = data(value);
            return;
        }
        if (tl > position || position > tr)
            return;

        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, position, value);
        update(2 * ind + 1, tm + 1, tr, position, value);
        t[ind] = calc(t[2 * ind], t[2 * ind + 1]);
    }

    data calc(data l, data r)
    {
        data temp(0);
        temp.sum = l.sum + r.sum;
        temp.pre = max(l.pre, l.sum + r.pre);
        temp.suf = max(r.suf, r.sum + l.suf);
        temp.best = max({l.best, r.best, l.suf + r.pre});
        return temp;
    }

    void res()
    {
        cout << t[1].best << endl;
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
    seg.res();

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        seg.update(1, 0, n - 1, a, b);
        seg.res();
    }
    return 0;
}
