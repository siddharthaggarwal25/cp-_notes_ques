#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[3][n];
    for (int i = 0; i < n; i++)
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    int dp[3][n];
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[2][0] = arr[2][0];

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + arr[1][i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + arr[2][i];
    }
    cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));

    return 0;
}
