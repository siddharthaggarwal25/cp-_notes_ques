#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> depth;
vector<vector<int>> up;
void dfs(int node, int parent, vector<vector<int>> &up)
{
    up[node][0] = parent;
    for (int i = 1; i < 20; i++)
    {
        int halfnode = up[node][i - 1];
        up[node][i] = up[halfnode][i - 1];
    }
    for (auto child : adj[node])
    {
        if (child == parent)   continue;
        depth[child] = depth[node] + 1;
        dfs(child, node, up);
    }
}
int kthparent(int node, int k)
{
    for (int i = 19; i >= 0; i--)
    {
        if (k >> i & 1)
            node = up[node][i];
    }
    return node;
}
int lca(int node1, int node2)
{

    if (depth[node2] > depth[node1])
        swap(node1, node2);
    int k = depth[node1] - depth[node2];
    node1 = kthparent(node1, k);
    if (node1 == node2)
        return node2;
    for (int i = 19; i >= 0; i--)
    {
        if (up[node1][i] == up[node2][i])
            continue;
        node1 = up[node1][i];
        node2 = up[node2][i];
    }
    return up[node1][0];
}
int distance(int node1, int node2)
{
    return depth[node1] + depth[node2] - 2 * depth[lca(node1, node2)];
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    depth.resize(n + 1, 0);
    up.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        up[i].assign(20, 0);
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 1, up);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int dis = distance(a, b);
        if (dis <= c)
            cout << b << endl;
        else
        {
            int leastcommon = lca(a, b);
            int left = depth[a] - depth[leastcommon];
            int right = depth[b] - depth[leastcommon];
            if (left >=  c)
            {
                cout << kthparent(a, c)<<endl;;
            }
            else
            {
                cout << kthparent(b, c - dis )<<endl;
            }
        }
    }

    return 0;
}