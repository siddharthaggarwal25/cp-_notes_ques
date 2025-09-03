#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    int cnt = 1;
    for (auto child : adj[node])
    {
        if (vis[child] == 1)
            continue;
        cnt += dfs(child, adj, vis);
    }
    return cnt;
}

int pow(int n, int k)
{
    if (k == 0)
        return 1;

    if (k % 2 == 0)
        return pow((n * n) % mod, k / 2) % mod;
    return (n * (pow((n * n) % mod, k / 2) % mod)) % mod;
}
int32_t main()
{
    int n, k;
    cin >> n >> k;

    int ans = pow(n, k);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;

        if (x == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> vis(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
            continue;

        int temp = dfs(i, adj, vis);

        temp = pow(temp, k);

        ans = (ans - temp + mod) % mod;
    }
    cout << ans << endl;

    return 0;
}