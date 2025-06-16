#include <bits/stdc++.h>
using namespace std;

map< pair< pair<int , int >, int > , int > mp;
vector<int> path;
queue<pair<int, int>> q;
vector<vector<int>> adj, par, vis;
int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    par.resize(n + 1, vector<int>(n + 1, -1));
    vis.resize(n + 1, vector<int>(n + 1, 0));
    int u, v, a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c;
        mp[{{a, b}, c}] = 1;
    }
    int last = -1;
    q.push({1, 1});
    par[1][1] = 1;

    while (!q.empty())
    {
        int lastnode = q.front().first;
        int node = q.front().second;
        q.pop();

        if (node == n)
        {
            last = lastnode;
            break;
        }
        if (vis[lastnode][node] == 1)
            continue;
        vis[lastnode][node] = 1;

        for (auto child : adj[node])
        {
            if (mp[{{lastnode, node}, child}] == 1)
                continue;
            if (par[node][child] == -1)
            {
                par[node][child] = lastnode;
                q.push({node, child});
            }
        }
    }

    if (last == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        int lastnode = n;
        path.push_back(lastnode);
        path.push_back(last);
        while (last != 1)
        {
            int parent = par[last][lastnode];
            lastnode = last;
            last = parent;
            path.push_back(parent);
        }
        cout << path.size() - 1 << "\n";
        reverse(path.begin(), path.end());
        for (auto it : path)
            cout << it << " ";
        cout << "\n";
    }

    return 0;
}