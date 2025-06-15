#include <bits/stdc++.h>
using namespace std;
#define int long long 
class SegmentTree
{
public:
    vector<pair<int, int>> t;
    SegmentTree(int len)
    {
        t.resize(4 * len);
    }

    void build(vector<int> &a, int ind, int tl, int tr)
    {
        if (tl == tr)
        {
            t[ind] = {a[tl], 1};
            return ;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * ind, tl, tm);
        build(a, 2 * ind + 1, tm + 1, tr);

        if (t[2 * ind].first == t[2 * ind + 1].first)
        {
            t[ind].first = t[2 * ind].first;
            t[ind].second = t[2 * ind].second + t[2 * ind + 1].second;
        }
        else if (t[2 * ind] < t[2 * ind + 1])
        {
            t[ind] = t[2 * ind];
        }
        else
        {
            t[ind] = t[2 * ind + 1];
        }
    }
    void update(int ind, int tl, int tr, int position, int value)
    {
        if (tl == position && tr == position)
        {
            t[ind] = {value, 1};
            return ;
        }
        if (position > tr || position < tl)
            return;
        int tm = (tl + tr) / 2;
        update(2 * ind, tl, tm, position, value);
        update(2 * ind + 1, tm + 1, tr, position, value);
        if (t[2 * ind].first == t[2 * ind + 1].first)
        {
            t[ind].first = t[2 * ind].first;
            t[ind].second = t[2 * ind].second + t[2 * ind + 1].second;
        }
        else if (t[2 * ind] < t[2 * ind + 1])
        {
            t[ind] = t[2 * ind];
        }
        else
        {
            t[ind] = t[2 * ind + 1];
        }
    }
    pair<int, int> query(int ind, int tl, int tr, int l, int r)
    {    
        if( l <=tl &&  tr <= r )return t[ind];
        if(  l > tr  || r < tl )return  { 1e9 , 0 };

        int tm = (tl + tr) / 2;
        pair<int, int> leftans, rightans;
        leftans = query(2 * ind, tl, tm, l, r);
        rightans = query(2 * ind + 1, tm + 1, tr, l, r);

        if (leftans.first == rightans.first)
        {
            return {leftans.first, leftans.second + rightans.second};
        }
        else if (leftans.first < rightans.first)
            return leftans;
        else
            return rightans;
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
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            seg.update(1, 0, n - 1, y, z);
        }
        else
        {
            auto ans = seg.query(1, 0, n - 1, y, z - 1);
            cout << ans.first<<" " <<ans.second << endl;
        }
    }
    return 0;
}