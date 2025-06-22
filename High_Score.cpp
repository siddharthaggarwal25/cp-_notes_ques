#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v, -w}});
    }

    const int INF = 1e16;
    vector<int> dis(n + 1, INF);
    dis[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            int u = it.first;
            int v = it.second.first;
            int wt = it.second.second;

            if (dis[u] != INF && dis[v] > dis[u] + wt)
            {
                dis[v] = dis[u] + wt;
            }
        }
    }

    bool hasNegativeCycle = false;
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second.first;
        int wt = it.second.second;

        if (dis[u] != INF && dis[v] > dis[u] + wt)
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << -dis[n] << endl;
    }

    return 0;
}
