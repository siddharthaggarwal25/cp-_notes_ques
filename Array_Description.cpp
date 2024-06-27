#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(100001, vector<int>(102, 0));
int main()
{
    int n, u;
    cin >> n >> u;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[0] == 0)
            {
                for (int j = 1; j <= u; j++)
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                dp[i][arr[i]] = 1;
            }
        }
        else
        {
            if (arr[i] == 0)
            {
                for (int j = 1; j <= u; j++)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
                }
            }
            else
            {
                int j = arr[i];
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    int mod = 1e9 + 7;
    int ans = 0;
    for (int i = 1; i <= u; i++)
    {
        ans += dp[n - 1][i];
        ans = ans % mod;
    }
    cout << ans << endl;
    return 0;
}