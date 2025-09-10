#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int par, vector<int> &color, vector<int> &parent, vector<vector<int>> &adj)
{
    color[node] = 1;
    parent[node] = par;
    for (auto child : adj[node])
    {

        if (color[child] == 0)
        {
            int temp = dfs(child, node, color, parent, adj);
            if (temp != -1)
                return temp;
        }
        else if( color[child ] == 1)
        {
            parent[child] = node;
            return child;
        }
    }

    color[node] = 2;
    return -1;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> color(n + 1, 0);
    vector<int> parent(n + 1);

    int node = -1;
    for (int i = 1; i <= n; i++)
    {

        if (color[i] == 0)
        {

            node = dfs(i, i, color, parent, adj);
            if (node != -1)
                break;
        }
    }

    // cout << node << endl;
    if (node == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int start = node;
        vector<int> cycle;
        while (true)
        {
            cycle.push_back(node);
            if (node == start && cycle.size() > 1)
                break;
            node = parent[node];
        }
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (auto it : cycle)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}