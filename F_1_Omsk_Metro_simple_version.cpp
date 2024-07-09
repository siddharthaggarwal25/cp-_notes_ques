#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    reverse( a.begin() , a.end());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int e = 0, price = 0;
    for (int i = 0; i < n; i++)
    {
        price += a[i].second;
        pq.push(a[i].second);
        e++;
        if (e < m)
            continue;
        if (e == m + 1)
        {
            e--;
            price = price - pq.top();
            pq.pop();
        }
        ans = max(ans, price + a[i].first * m);
    }

    cout<< ans;

    return 0;
}