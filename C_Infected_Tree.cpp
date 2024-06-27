#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &sz, vector<vector<int>> &adj)
{
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, sz, adj);
        sz[node] += sz[child];
    }
}
int solve(int node, int parent, vector<int> &sz, vector<vector<int>> &adj)
{
    if (adj[node].size() == 1 && node != 1) return 0;
    vector<int> v;
    for (auto child : adj[node])
    {
        if (child != parent)
            v.push_back(child);
    }
    if (v.size() > 1)
    {
        int leftnode = v[0];
        int rightnode = v[1];

        int a = sz[leftnode] - 1 + solve(rightnode, node, sz, adj);
        int b = sz[rightnode] - 1 + solve(leftnode, node, sz, adj);

        return max(a, b);
    }else {
        return sz[v[0]]-1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        vector<int> sz(n + 1, 1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1, -1, sz, adj);

        int val = solve(1, -1, sz, adj);
        cout << val << endl;
    }
    return 0;
}