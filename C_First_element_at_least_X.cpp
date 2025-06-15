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
        t[ind] = max(t[2 * ind], t[2 * ind + 1]);
    }
    void update(int ind, int tl, int tr, int position, int value)
    {
        if (tl == position && tr == position)
        {
            t[ind] = value;
            return;
        }
        if (tl > position || tr < position)
            return;
        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, position, value);
        update(2 * ind + 1, tm + 1, tr, position, value);
        t[ind] = max(t[2 * ind], t[2 * ind + 1]);
    }

    int query(int ind, int tl, int tr, int k)
    {
        if (tl == tr)
        {
            if (t[ind] >= k)
                return tl;
            return -1;
        }
        int tm = (tl + tr) / 2;
        if (t[2 * ind] >= k)
            return query(2 * ind, tl, tm, k);
        else if (t[2 * ind + 1] >= k)
            return query(2 * ind + 1, tm + 1, tr, k);
        else
            return -1;
    }
};
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree seg(n);
    seg.build(a ,1 , 0 ,n-1);
    while (m--)
    {
        int x;
        cin >>x;
          
        if (x == 1)
        {
            int y, z;
            cin >> y >> z;
            seg.update(1 , 0 , n-1 , y, z );
        }
        else
        {
            int y;
            cin >> y;
            int ans  = seg.query( 1 ,0 , n-1 , y);
            cout<<ans<<endl;
        }
    }
    return 0;
}