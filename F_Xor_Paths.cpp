#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans(int i, int j, vector<vector<int>> &adj, int n, int m, int x, int k)
{
    if (i > n || j > m)
        return 0;
    if (i == n && j == m)
    {
        if (((adj[n][m]) ^ x) == k)
            return 1;
        return 0;

    }
        return ans(i + 1, j, adj, n, m, (adj[i][j]) ^ x, k) + ans(i, j + 1, adj, n, m, (adj[i][j]) ^ x, k);
}
int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    cout << ans(0, 0, adj, n - 1, m - 1, 0, k);
    return 0;
}