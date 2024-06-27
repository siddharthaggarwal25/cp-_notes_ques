#include <bits/stdc++.h>
using namespace std;

vector<int> traversal;
int dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &size)
{
    traversal.push_back(node);
    int sz = 1;
    for (auto child : adj[node])
    {

        if (child == parent)
            continue;
        sz += dfs(child, node, adj, size);
    }
    return size[node] = sz;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    vector<int> size(n + 1, 0);
    dfs(1, 0, adj, size);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[traversal[i]] = i;
    }
    while (q--)
    {
        int u, k;
        cin >> u >> k;
        if (size[u] < k)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << traversal[mp[u] + k - 1] << endl;
        }
    }

    return 0;
}
