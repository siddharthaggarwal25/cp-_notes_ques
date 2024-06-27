#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> parent;
vector<int> sz;
vector<int> par_;
void make_set(int n)
{
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find_set(int x)
{
    if (x == parent[x])
        return x;
    parent[x] = find_set(parent[x]);
}
void union_set(int a, int b)
{
    int repa = find_set(a);
    int repb = find_set(b);
    if (repa == repb)
        return;
    if (sz[repb] > sz[repa])
        swap(repb, repa);
    sz[repa] += sz[repb];
    parent[repb] = repa;
}
void dfs(int node, int par)
{ par_[node] = par;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;

        dfs(child, node);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, u, v});
        }
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());
        make_set(n);
        adj.resize(n + 1);
        par_.resize(n + 1);
        int u = 0, v = 0, w = 0;
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][1];
            int b = edges[i][2];
            int heada = find_set(a);
            int headb = find_set(b);
            if (heada == headb)
            {
                u = a;
                v = b;
                w = edges[i][0];
                continue;
            }
            adj[a].push_back(b);
            adj[b].push_back(a);
            union_set(a, b);
        }
        dfs(v, v);
        vector<int> ans;
        while (u != v)
        {
            ans.push_back(u);
            u = par_[u];
        }
        ans.push_back(v);
        cout << w << " " << ans.size() << endl;
        for (auto val : ans)
            cout << val << " ";
        cout << endl;

        adj.clear();
        sz.clear();
        parent.clear();
        par_.clear();
    }
    return 0;
}