#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>> adj;
vector<vector<int>> radj;
vector<int> value;
vector<int> vis;
vector<int> order;
const int mod = 1e9 + 7;
void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
    order.push_back(node);
}
void dfs2(int node, vector<int> &component)
{
    vis[node] = 1;
    component.push_back(node);
    for (auto child : radj[node])
    {
        if (vis[child])
            continue;
        dfs2(child, component);
    }
}
int32_t main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    radj.resize(n + 1);
    value.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
    vector<int> code(n + 1);
    vector<int> root(n + 1);
    int cost = 0;
    int ways = 1;
    int ct = 0;
    vis.assign(n + 1, 0);
    for (auto x : order)
    {
        if (vis[x])
            continue;
        ct++;

        vector<int> component;
        dfs2(x, component);
        for (auto y : component)
        {
            code[y] = ct;
            root[y] = x;
        }
        int minmun = 1e18;
        int freq = 0;
        for (auto y : component)
        {
            minmun = min(minmun, value[y]);
        }
        for (auto y : component)
        {
            if (value[y] == minmun)
                freq++;
        }
        cost = cost + minmun;
        ways = (ways * freq) % mod;
    }
    cout << cost << " " << ways << endl;
    return 0;
}