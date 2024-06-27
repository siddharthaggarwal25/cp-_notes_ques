#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100001, vector<int>(101, -1));
void bfs(int w, vector<int> &a, vector<vector<int>> &adj, int n)
{
    queue<int> q;
    vector<int> vis(100001, 0);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == w)
        {
            dp[i][w] = 0;
            vis[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                q.push(child);
                dp[child][w] = dp[node][w] + 1;
            }
        }
    }
}
int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= k; i++)
        bfs(i, a, adj, n);

    for (int i = 1; i <= n; i++)
    {
        sort(dp[i].begin() + 1, dp[i].begin() + k + 1);
        int ans = 0;
        for (int j = 1; j <= s; j++)
            ans += dp[i][j];
        cout << ans << ' ';
    }
    return 0;
}