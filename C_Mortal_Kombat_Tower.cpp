#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int ind, int person, vector<int> &v, int n, vector<vector<int>> &dp)
{
    if (ind > n) return 0;
    if (dp[ind][person] != -1) return dp[ind][person];

    if (person == 0)
    {
        int a = v[ind] + solve(ind + 1, 1, v, n, dp);
        int b = 1e18;
        if (ind + 1 <= n) b = v[ind] + v[ind + 1] + solve(ind + 2, 1, v, n, dp);
        return dp[ind][person] = min(a, b);
    }
    else
    {
        int a = solve(ind + 1, 0, v, n, dp);
        int b = 1e18;
        if (ind + 1 <= n) b = solve(ind + 2, 0, v, n, dp);
        return dp[ind][person] = min(a, b);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) cin >> v[i];
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        cout << solve(1, 0, v, n, dp) << "\n";
    }
    return 0;
}
