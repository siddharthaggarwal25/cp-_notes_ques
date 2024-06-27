#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<int> vis;
vector<int> test;
void dfs(int node)
{
    test.push_back(node);
    vis[node] = true;
    for (auto child : adj[node])
    {
        if (vis[child] == 1) continue;
        dfs(child);
    }
}
int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    vector<int> spe;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        spe.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> edges;
    int max = -1;
    for (int i = 0; i < k; i++)
    {
        test.clear();
        dfs(spe[i]);
        int v = test.size();
        if (v > max)
            max = v;
        v = v * (v - 1) / 2;
        edges.push_back(v);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            count++;
        }
    }
    edges.push_back(count * (count - 1) / 2);
    edges.push_back(count * max);
    int ans = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        ans += edges[i];
    }
    ans = ans - m;
    cout << ans << endl;

    return 0;
}