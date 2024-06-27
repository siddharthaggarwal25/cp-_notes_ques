#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<int>> adj;
map<pair<int, int>, int> mp;
vector<int> dis;
vector<int> par;
int32_t main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dis.assign(n + 1, 1e18);
    par.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (mp[{x, y}] == 0)
        {
            mp[{x, y}] = w;
            mp[{y, x}] = w;
        }
        else
        {
            mp[{x, y}] = min(mp[{x, y}], w);
            mp[{y, w}] = min(mp[{x, y}], w);
        }
    }
    dis[1] = 0;
    par[1] = 1;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto child : adj[node])
        {
            if (dis[child] > distance + mp[{child, node}])
            {
                dis[child] = distance + mp[{child, node}];
                pq.push({dis[child], child});
                par[child] = node;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << " ";
    if (dis[n] == 1e18)
        cout << -1 << endl;
    else
    {
        stack<int> ans;
        while (n != 1)
        {
            ans.push(n);
            n = par[n];
        }
        cout << 1 << " ";
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
    }

    return 0;
}