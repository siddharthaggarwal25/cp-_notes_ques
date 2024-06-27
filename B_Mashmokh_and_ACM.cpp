#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int mod = 1e9 + 7;
vector<vector<int>> dp;
int count(int last, int len)
{
    if (k == len)
        return 1;
    if (dp[last][len] != -1)
        return dp[last][len];
    int ans = 0;
    for (int j = last; j <= n; j += last)
    {
        ans += count(j, len + 1);
        ans = ans%mod;
    };
    return dp[last][len] = ans % mod;
}
int32_t main()
{
    cin >> n >> k;
    dp.assign(n + 1, vector<int>(k + 1, -1));
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += count(i, 1);
        ans = ans%mod;
    }
    cout << ans << endl;
    return 0;
}