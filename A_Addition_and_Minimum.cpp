#include <bits/stdc++.h>
using namespace std;
#define int long long 
class Segmenttree
{
public:
    vector<int> t, islazy, unprop;
    Segmenttree(int len)
    {
        t.resize(4 * len, 0);
        islazy.resize(4 * len, 0);
        unprop.resize(4 * len, 0);
    }
    void apply(int ind, int tl, int tr, int val)
    {
        if (tl != tr)
        {
            islazy[ind] = 1;
            unprop[ind] += val;
        }
        t[ind] = t[ind] +  val;
    }

    void push_down(int ind, int tl, int tr)
    {
        if (!islazy[ind])
            return;
        islazy[ind] = 0;
        int tm = (tl + tr) / 2;
        apply(2 * ind, tl, tm, unprop[ind]);
        apply(2 * ind +1, tm+1, tr, unprop[ind]);
        unprop[ind] = 0;
    }
    void update(int ind, int tl, int tr, int l, int r, int value)
    {

        if (l <= tl && tr <= r)
        {
            apply(ind, tl, tr, value);
            return;
        }
        if (l > tr || r < tl)
            return;

        push_down(ind, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, l, r, value);
        update(2 * ind + 1, tm + 1, tr, l, r, value);
        t[ind] = min(t[2 * ind], t[2 * ind + 1]);
    }

    int query(int ind, int tl, int tr, int l, int r)
    {

        if (l <= tl && tr <= r)
            return t[ind];
        if (l > tr || r < tl)
            return 1e18 ;
        push_down(ind, tl, tr);
        int tm = (tl + tr) / 2;
        int leftans = query(2 * ind, tl, tm, l, r);
        int rightans = query(2 * ind + 1, tm + 1, tr, l, r);
        return min(leftans, rightans);
    }
};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    Segmenttree seg(n);
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
            cin >> l >> r;
            int ans = seg.query(1, 0, n - 1, l, r - 1);
            cout << ans << endl;
        }
    }

    return 0;
}