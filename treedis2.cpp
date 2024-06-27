#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>> adj;
vector<int> dp, size_, ans;

void dfs(int node, int parent)
{
    size_[node] = 1;
    dp[node] = 0;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node);
        dp[node] += dp[child] + size_[child];
        size_[node] += size_[child];
    }
}
void rerooting(int node, int parent)
{
    ans[node] = dp[node];
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dp[node] = dp[node] - dp[child] - size_[child];
        size_[node] = size_[node] - size_[child];
        dp[child] = dp[child] + dp[node] + size_[node];
        size_[child] = size_[child] + size_[node];

        rerooting(child, node);

        dp[child] = dp[child] - dp[node] - size_[node];
        size_[child] = size_[child] - size_[node];
        dp[node] = dp[node] + dp[child] + size_[child];
        size_[node] = size_[node] + size_[child];
    }
}
int32_t main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    ans.resize(n + 1);
    size_.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    rerooting(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}