#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<vector<int>> adj(N);
vector<int> depth(N);
vector<vector<int>> up(N, vector<int>(20));

void dfs(int node, int parent)
{
    up[node][0] = parent;
    for (int i = 1; i < 20; i++)
    {
        int halfParent = up[node][i - 1];
        up[node][i] = up[halfParent][i - 1];
    }
    for (auto child : adj[node])
    {  if( child == parent ) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}
int kthparent(int node, int k)
{
    for (int i = 19; i >= 0; i--)
    {
        if (k & (1 << i))
            node = up[node][i ];
    }
    return node ;
}
int lca(int a, int b)
{
    if (depth[b] > depth[a])
        swap(a, b);
    int climb = depth[a] - depth[b];
    a = kthparent(a, climb);
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
    {
        if (up[a][i] == up[b][i])
            continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}
int distance(int a, int b)
{
    return (depth[a] + depth[b] - 2 * depth[lca(a, b)]);
}
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << distance(a, b) << endl;
    }

    return 0;
}