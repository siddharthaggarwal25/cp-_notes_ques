#include <bits/stdc++.h>
using namespace std;
#define int long long 
void dfs(int node, int parent, vector<vector<int>> &dp, vector<vector<int>> &adj)
{

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, dp, adj);
        dp[node][0] += max(dp[child][0], dp[child][1]);
    }

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dp[node][1] = max(dp[node][1], dp[node][0] + 1 + dp[child][0] - max(dp[child][0], dp[child][1]));
    }
}
int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dfs(1, -1, dp, adj);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}