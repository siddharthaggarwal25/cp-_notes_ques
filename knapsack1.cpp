#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[2][n];
    int dp[2][n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0][i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[1][i];
    }

    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[0][i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + arr[1][i]);
    }
    
    

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;

    return 0;
}