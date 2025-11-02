#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs(child, vis, adj, st);
    }
    st.push(node);
}
void dfs2(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &king, int cnt)
{
    vis[node] = 1;
    king[node] = cnt;
    for (auto child : adj[node])
    {
        if (vis[child])
            continue;
        dfs2(child, vis, adj, king, cnt);
    }
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), adjt(n + 1);
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    stack<int> st;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjt[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis1[i])
            dfs(i, vis1, adj, st);
    }
    vector<int> king(n + 1);
    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis2[node])
        {
            cnt++;
            dfs2(node, vis2, adjt, king, cnt);
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        cout << king[i] << " ";
    cout << endl;

    return 0;
}