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
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    vector<int> dis(n + 1, 0);
    vector<int> par(n + 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
         
            if (dis[u] != 1e18 && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                par[v] = u;
            }
        }
    }

    int node = -1;
    for (auto edge : edges)
    {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (dis[u] != 1e18 && dis[v] > dis[u] + w)
        {
            dis[v] = dis[u] + w;
            par[v] = u;
            node = v;
            break;
        }
    }

    if (node == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<int> cycle;
        for (int i = 0; i < n; i++)
        {
            node = par[node];
        }

        for (int start = node;; start = par[start])
        {
            cycle.push_back(start);
            if (start == node && cycle.size() > 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());

        for (auto it : cycle)
            cout << it << " ";
    }

    return 0;
}
