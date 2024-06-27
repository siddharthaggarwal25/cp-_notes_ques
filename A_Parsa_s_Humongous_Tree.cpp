#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int node, int parent, vector<pair<int, int>> &val, vector<vector<int>> &adj, vector<vector<int>> &dp)
{
    for (auto child : adj[node])
    {
        if (child == parent) continue;
        dfs(child, node, val, adj, dp);
        dp[node][0] += max(abs(val[node].first - val[child].first) + dp[child][0], abs(val[node].first - val[child].second) + dp[child][1]);
        dp[node][1] += max(abs(val[node].second - val[child].first) + dp[child][0], abs(val[node].second - val[child].second) + dp[child][1]);
    }
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> val(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i].first >> val[i].second;
        }
         int x, y;
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dfs(1, 1, val, adj, dp);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
    return 0;
}