#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int dp[101][3];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 1; i <= n; i++)
    {

        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;

        if (arr[i] == 1)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][2] + 1;
        }
        else if (arr[i] == 2)
        {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else if (arr[i] == 3)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        else
        {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][2] = dp[i - 1][2] + 1;
        }

    }
        cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

    return 0;
}