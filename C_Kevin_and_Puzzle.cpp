#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    int dp[n + 1][2] = {0};
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][0] % mod;
        if (v[i - 1] == v[i])dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
        if (i - 2 >= 0 && v[i - 2] +1 == v[i] ) dp[i][0] = (dp[i][0] + dp[i - 2][0]) % mod;
    }
    // cout<<"a"<<" "<< "b"<<endl;
    // for( auto it : dp)cout<<it[0]<<" "<< it[1]<<endl;
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
