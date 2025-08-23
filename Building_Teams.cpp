#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int cur, vector<int> &color, vector<vector<int>> &adj)
{
    color[node] = cur;
    for (auto child : adj[node])
    {
        if (color[child] == -1)
        {
            bool temp = dfs(child, cur ^ 1, color, adj);
            if (temp == false)
                return false;
        }
        else if (color[child] == cur)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    bool check = true;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            check = check & dfs(i, 0, color, adj);
        }
        if( !check)break;
    }
    if (!check)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {

        for (int i = 1; i <= n; i++)
            cout << color[i] + 1 << " ";
        cout << endl;
    }
    return 0;
}