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
            t[ind] = a[tl];

        int tm = (tr + tl) / 2;
        build(a, 2 * ind, tl, tm);
        build(a, 2 * ind + 1, tm + 1, tr);
        t[ind] = t[2 * ind] + t[2 * ind + 1];
    }

    int query(int ind, int tl, int tr, int l, int r)
    {
        if (tr < l || tl > r)
            return 0;
        if (l <= tl && tr <= r)
            return t[ind];
        int tm = (tl + tr) / 2;
        leftans = query(2 * ind, tl, tm, l, r);
        rightans = query(2 * ind + 1, tm + 1, tr, l, r);
        return leftans + rightans;
    } // 1  , tl ,tr , l , r

    void update(int ind, int tl, int tr, int position, int value)
    {
        if (tl == position && tr == position)
            t[ind] = value;
        if (position > tr || position < tl)
            return;
        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm + 1, position, value);
        update(2 * ind + 1, tm + 1, tr, position, value);
        t[ind] = t[2 * ind] + t[2 * ind + 1]
    } // 1  , 0 , len-1  , x , y

}

int
main()
{

    return 0;
}