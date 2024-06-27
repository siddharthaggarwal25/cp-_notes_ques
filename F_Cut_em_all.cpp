#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> sz;
void dfs(int node, int parent)
{
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node);
        sz[node] += sz[child];
    }
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    if (n % 2 != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (sz[i] % 2 == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}