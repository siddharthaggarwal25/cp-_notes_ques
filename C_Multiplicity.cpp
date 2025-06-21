#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int solve(int ind, int div, int n, vector<int> &v, vector<unordered_map<int, int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][div] != 0)
        return dp[ind][div];
    int take = 0;
    if (v[ind] % div == 0)
    {
        take = solve(ind + 1, div + 1, n, v, dp) + 1;
        take = take % mod;
    }

    int nottake = solve(ind + 1, div, n, v, dp) % mod;

    return dp[ind][div] = (take + nottake) % mod;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<unordered_map<int, int>> dp(n + 1);

    int ans = solve(0, 1, n, v, dp) % mod;
    cout << ans << endl;

    return 0;
}