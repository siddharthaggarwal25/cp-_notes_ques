#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - k; j < i; j++)
        {
            if (j >= 0)
                dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
        }
    }
    // for (int i = 0; i < n; i++)
        cout << dp[n-1] << " ";
    return 0;
}