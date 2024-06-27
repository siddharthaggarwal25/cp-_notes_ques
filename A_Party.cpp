#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &depth)
{
    vis[node ] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            depth[child] = 1 + depth[node];
            dfs(child, vis, adj, depth);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != -1)
        {
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
        else
        {
            s.push_back(i);
        }
    }
    vector<int> depth(n + 1, 0);
    vector<int> vis(n + 1,  0);
    for (int i = 0; i < s.size(); i++)
    {
        dfs(s[i], vis, adj, depth);
    }
    int ans = *max_element(depth.begin(), depth.end());
    cout << ans + 1 << endl;
    return 0;
}