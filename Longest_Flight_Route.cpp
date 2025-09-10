#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child] == 1)
            continue;
        dfs(child, st, vis, adj);
    }
    st.push(node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> dis(n + 1, -1e9);
    vector<int> vis(n + 1, -1);
    vector<int> parent(n + 1);
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1, st, vis, adj);
    dis[1] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dis[node] == -1e9)
            continue;

        for (auto child : adj[node])
        {
            if (dis[child] < 1 + dis[node])
            {
                parent[child] = node;
                dis[child] = 1 + dis[node];
            }
        }
    }

    if (vis[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int node = n;
        while (node != 1)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}