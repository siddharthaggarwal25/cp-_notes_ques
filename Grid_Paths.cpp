#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int count(int i, int j, vector<vector<char>> &adj, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (adj[i][j] == '*')
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = count(i - 1, j, adj, dp) % mod;
    int up = count(i, j - 1, adj, dp) % mod;
    return dp[i][j] = (left + up) % mod;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> adj(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    if (adj[0][0] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << count(n - 1, n - 1, adj, dp);

    return 0;
}