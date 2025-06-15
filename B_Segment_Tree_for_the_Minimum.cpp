#include <bits/stdc++.h>
using namespace std;
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
        build(a, 2 * ind +1, tm + 1, tr);
        t[ind] = min(t[2 * ind], t[2 * ind + 1]);
    }

    void update(int ind, int tl, int tr, int position, int value)
    {
        if (tl == position && tr == position)
        {
            t[ind] = value;
            return;
        }
        if (position < tl || position > tr)
            return;

        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, position, value);
        update(2 * ind + +1, tm + 1, tr, position, value);
        t[ind] = min(t[2 * ind], t[2 * ind + 1]);
    }

    int query(int ind, int tl, int tr, int l, int r)
    {

        if (l <= tl && tr <= r)
            return t[ind];
        if (l > tr || r < tl)
            return 1e9;
        int tm = (tl + tr) / 2;
        int leftans = query(2 * ind, tl, tm, l, r);
        int rightans = query(2 * ind + 1, tm + 1, tr, l, r);
        return min(leftans, rightans);
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SegmentTree* seg = new SegmentTree( n);
    seg->build( a ,1 , 0 , n-1 );
    while (m--)
    { int x, y , z;
        cin>>x>>y>>z;
        if( x==1){
            seg->update( 1 , 0, n-1 , y, z);

        }else{
            int ans  = seg->query( 1 , 0 , n-1 , y, z-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}