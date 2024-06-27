#include <bits/stdc++.h>
using namespace std;
#define int long long 
int weight[105], value[105];
int dp[105][100005];
int32_t main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i <= w; i++)
    {
        if (i < weight[0])
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = value[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = max(dp[i - 1][j], (j - weight[i] >= 0) ? (value[i] + dp[i - 1][j - weight[i]]) : 0);
        }
    }
    cout << dp[n - 1][w] << endl;
    

    return 0;
}