#include <bits/stdc++.h>
using namespace std;
#define int long long 

int mod = 1e9 + 7 ;
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
            unval[ind] = (unval[ind] * val)%mod;
        }
        t[ind] = (t[ind] * val)%mod;
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
        int leftans = query(2 * ind, tl, tm, l, r)%mod;
        int rightans = query(2 * ind + 1, tm + 1, tr, l, r)%mod;
        return (leftans + rightans)%mod;
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
        t[ind] = (t[2 * ind]%mod + t[2 * ind + 1]%mod)%mod;
    }

    void build( int ind , int tl , int tr){
         if( tl== tr)return ;
        int tm  = ( tl + tr)/2;
        build( 2*ind , tl ,tm );
        build( 2*ind  +1  , tm+1 , tr);
        t[ind] = t[2*ind] + t[2*ind+1];
    }
};

int32_t main()
{

    int n, m;
    cin >> n >> m;
    SegmentTree seg(n);
    seg.build( 1 , 0 , n-1);
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
            cin>>l>>r;
            cout << seg.query(1, 0, n - 1, l, r - 1) << endl;
        }
    }
    return 0;
}