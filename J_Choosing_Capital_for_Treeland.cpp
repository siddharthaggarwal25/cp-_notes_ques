#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<int> value;
vector<int> ans;
void dfs(int node, int parent)
{
    value[node] = 0;
    for (auto child : adj[node])
    {
        if (child.first == parent)
            continue;

        dfs(child.first, node);
        value[node] += child.second + value[child.first];
    }
}
void rerooting(int node, int parent)
{
    ans[node] = value[node];
    for (auto child : adj[node])
    {
        if (parent == child.first)
            continue;
        if (child.second)
            value[child.first] = value[node] - 1;
        else
            value[child.first] = value[node] + 1;
        rerooting(child.first, node);
    }
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    ans.resize(n + 1);
    value.resize( n+1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    dfs(1, 0);
    rerooting(1, 0);
    int result = *min_element(ans.begin() + 1, ans.end());
    cout << result << endl;
    for (int i = 1; i <= n; i++)
    {
        if (result == value[i])
            cout << i << " ";
    }

    return 0;
}