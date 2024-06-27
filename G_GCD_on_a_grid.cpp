#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        int ans = 1;
        int gcd = __gcd(v[0][0], v[n - 1][m - 1]);
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int k = 1; k * k <= gcd; k++)
        {
            if (gcd % k != 0)
                continue;
            else
            {
                vector<int> times = {k, gcd / k};
                for (auto el : times)
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            if (v[i][j] % el == 0)
                                dp[i][j] = 1;
                            else
                                dp[i][j] = 0;

                            if (i == 0 && j == 0)
                                continue;
                            else if (i == 0)
                                dp[i][j] = dp[i][j - 1] + dp[i][j];
                            else if (j == 0)
                                dp[i][j] = dp[i - 1][j] + dp[i][j];
                            else
                                dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i][j - 1] + dp[i][j]);
                        }
                    }
                    if (dp[n - 1][m - 1] == n + m - 1)
                        ans = max(ans, el);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}